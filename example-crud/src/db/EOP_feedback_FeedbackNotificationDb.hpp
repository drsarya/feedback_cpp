
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
		migration.addFile(2 /* start from version 1 */, DATABASE_MIGRATIONS "/002_init.sql");
		// TODO - Add more migrations here.
		migration.migrate(); // <-- run migrations. This guy will throw on error.

		auto version = executor->getSchemaVersion();
		OATPP_LOGD("FeedbackNotificatonDb", "Migration - OK. Version=%lld.", version);
	}
		
		QUERY(createNotificationFeedback,
			"insert into  FeedbackNotification (feedbackId, userId, description) values " 
			"(:notification.feedbackId, :notification.userId, :notification.description );",
			PARAM(oatpp::Object<FeedbackNotificationDto>, notification))


		QUERY(getNotificationById,
			"SELECT  *  FROM  FeedbackNotification "
			"WHERE  id=:id;",
			PARAM(oatpp::Int32, id))
	 
		QUERY(readNotificationFeedback,
			"UPDATE  FeedbackNotification "
			"SET notificationStatus = 2 "
			"WHERE id = :id;",
			PARAM(oatpp::Int32, id))
		 
		QUERY(getNotificationsForUserId,
			"SELECT * FROM FeedbackNotification "
			"WHERE  userId=:userId and notificationStatus = 1 order by creationDate desc;",
			PARAM(oatpp::String, userId))

		QUERY(deleteReadNotifications,
			"delete FROM feedbackNotification WHERE notificationStatus = 2;")
};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_FEEDBACKNOTIFICATONDB_HPP
