
#ifndef CRUD_USERSERVICE_HPP
#define CRUD_USERSERVICE_HPP

#include "db/EOP_feedback_FeedbackNotificationDb.hpp"
#include "dto/PageDto.hpp"
#include "dto/StatusDto.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class FeedbackNotificationService {
private:
	typedef oatpp::web::protocol::http::Status Status;
private:
	OATPP_COMPONENT(std::shared_ptr<FeedbackNotificatonDb>, m_database); // Inject database component
public:

	oatpp::Object<FeedbackNotificationDto> createNotificationFeedback(const oatpp::Object<FeedbackNotificationDto>& dto);
	oatpp::Object<FeedbackNotificationDto> readNotificationFeedback(const oatpp::UInt32& id);
	oatpp::Vector<oatpp::Object<FeedbackNotificationDto>>> getNotificationsForUserId(const oatpp::String& userId);
	oatpp::Object<StatusDto> deleteReadNotifications();
};

#endif //CRUD_USERSERVICE_HPP
