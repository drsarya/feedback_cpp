
#ifndef CRUD_FeedbackNotificatonDb_HPP
#define CRUD_FeedbackNotificatonDb_HPP

#include "dto/EOP_feedback_FeedbackNotificationDto.hpp"
#include "oatpp-sqlite/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

/**
 * FeedbackNotificatonDb client definitions.
 */
class FeedbackNotificatonDb : public oatpp::orm::DbClient {
public:

	FeedbackNotificatonDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
		: oatpp::orm::DbClient(executor)
	{

		oatpp::orm::SchemaMigration migration(executor);
		migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/001_init.sql");
		// TODO - Add more migrations here.
		migration.migrate(); // <-- run igrations. This guy will throw on error.

		auto version = executor->getSchemaVersion();
		OATPP_LOGD("FeedbackNotificatonDb", "Migration - OK. Version=%lld.", version);
	}

	QUERY(createNotificationFeedback,
		"insert into   feedback_notification (feedback_id, user_id, description) values "
		"(:notification.feedbackId, :notification.userId, :notification.description ) ;",
		PARAM(oatpp::Object<FeedbackNotificationDto>, notification))


		QUERY(getNotificationById,
			"SELECT  id, feedback_id as feedbackId,user_id as userId, description, notification_status as notificationStatus, creation_date as creationDate"
			" FROM   feedback_notification "
			"WHERE  id=:id;",
			PARAM(oatpp::Int32, id))

		QUERY(readNotificationFeedback,
			"UPDATE   feedback_notification "
			"SET notification_status = 2 "
			"WHERE id = :id;",
			PARAM(oatpp::Int32, id))

		QUERY(getNotificationsForUserId,
			"SELECT id, feedback_id as feedbackId,user_id as userId, description, notification_status as notificationStatus, creation_date as creationDate  FROM  feedback_notification "
			"WHERE  user_id=:userId and notification_status = 1 order by creation_date desc;",
			PARAM(oatpp::String, userId))

		QUERY(deleteReadNotifications,
			"delete FROM feedback_notification WHERE notification_status = 2;")
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_FEEDBACKNOTIFICATONDB_HPP
