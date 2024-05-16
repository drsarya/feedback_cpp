
#ifndef CRUD_FEEDBACKNOTIFICATIONSERVICE_HPP
#define CRUD_FEEDBACKNOTIFICATIONSERVICE_HPP

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
	oatpp::Object<FeedbackNotificationDto> getNotificationById(const oatpp::Int32& id);
	oatpp::Object<FeedbackNotificationDto> readNotificationFeedback(const oatpp::Int32& id);
	oatpp::Vector<oatpp::Object<FeedbackNotificationDto>> getNotificationsForUserId(const oatpp::String& userId);
	oatpp::Object<StatusDto> deleteReadNotifications();
};

#endif //CRUD_FEEDBACKNOTIFICATIONSERVICE_HPP