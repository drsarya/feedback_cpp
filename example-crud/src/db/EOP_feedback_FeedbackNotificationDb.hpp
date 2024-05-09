
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

	}
	QUERY(createNotificationFeedback,
		"insert into feedback.feedback_notification(feedback_id, user_id, description) values " 
		"(:notification.feedbackId, :notification.userId, :notification.description );",
		PARAM(oatpp::Object<FeedbackNotificationDto>, notification))

		QUERY(readNotificationFeedback,
			"UPDATE feedback.feedback_notification "
			"SET read_status = 2 "
			"WHERE id = :notification.id;",
			PARAM(oatpp::Int32, id))

		QUERY(getNotificationsForUserId,
			"SELECT * FROM feedback.feedback_notification "
			"WHERE  user_id=:userId and read_status = 1 order by creation_date desc;",
			PARAM(oatpp::String, userId)

		QUERY(getNotificationById,
			"SELECT * FROM feedback.feedback_notification "
			"WHERE  id=:id;",
			PARAM(oatpp::Int32, id))


		QUERY(deleteReadNotifications,
			"delete FROM feedback.feedback_notification WHERE read_status = 2;")

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_FEEDBACKNOTIFICATONDB_HPP
