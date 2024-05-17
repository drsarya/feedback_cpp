 
#ifndef CRUD_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP
#define CRUD_PUBLIC_FEEDBACKNOTIFICATIONSERVICE_HPP

#include "service/EOP_feedback_FeedbackNotificationService.hpp"

#include "oatpp/core/macro/component.hpp"

class FeedbackServiceMapper {
private:
	OATPP_COMPONENT(std::shared_ptr<FeedbackNotificationService>, m_real_service); // Inject service
public:

	oatpp::Object<FeedbackNotificationDto> mapToOatppFeedbackNotification(const FeedbackNotification* dto);
	void fromDtoToFeedbackNotification(const oatpp::Object<FeedbackNotificationDto>& dto, FeedbackNotification* feedbackNotification);

	void createNotificationFeedback(FeedbackNotification*, FeedbackNotification*);
	void getNotificationById(int id, FeedbackNotification*);
	void readNotificationFeedback(int id, FeedbackNotification*);
	void getNotificationsForUserId(char* userId, FeedbackNotification*);
	void deleteReadNotifications();

};

#endif //CRUD_PUBLIC_FEEDBACKSERVICE_HPP
 