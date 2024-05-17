#include "public/feedback_notification/EOP_feedback_FeedbackNotificationService.h"
#include "public/feedback_notification/EOP_feedback_FeedbackNotificationService.hpp"


oatpp::Object<FeedbackNotificationDto> mapToOatppFeedbackNotification(const FeedbackNotification* dto) {
	oatpp::Object<FeedbackNotificationDto> feedbackNotificationDto;

	feedbackNotificationDto->id = dto->id;
	feedbackNotificationDto->feedbackId = dto->feedbackId;
	feedbackNotificationDto->userId = dto->userId;
	feedbackNotificationDto->description = dto->description;
	feedbackNotificationDto->notificationStatus = dto->notificationStatus;
	feedbackNotificationDto->creationDate = dto->creationDate;

	return feedbackNotificationDto;
}

void fromDtoToFeedbackNotification(const oatpp::Object<FeedbackNotificationDto>& dto, FeedbackNotification* feedbackNotification) {
	feedbackNotification->id = dto->id;
	feedbackNotification->feedbackId = dto->feedbackId;
	feedbackNotification->userId = (char*)dto->userId->c_str();
	feedbackNotification->description = (char*)dto->description->c_str();
	feedbackNotification->notificationStatus = dto->notificationStatus;
	feedbackNotification->creationDate = (char*)dto->creationDate->c_str();
}

void FeedbackServiceMapper::createNotificationFeedback(FeedbackNotification* notification, FeedbackNotification* newNotification) {
	auto mappedObject = mapToOatppFeedbackNotification(notification);
	auto notificationOatpp = m_real_service->createNotificationFeedback(mappedObject);
	fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void FeedbackServiceMapper::getNotificationById(int id, FeedbackNotification* newNotification) {
	auto notificationOatpp = m_real_service->getNotificationById(id);
	fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void FeedbackServiceMapper::readNotificationFeedback(int id, FeedbackNotification* newNotification) {
	auto notificationOatpp = m_real_service->readNotificationFeedback(id);
	fromDtoToFeedbackNotification(notificationOatpp, newNotification);
}

void FeedbackServiceMapper::getNotificationsForUserId(char* userId, FeedbackNotification* notifications) {
	auto feedbackOatpp = m_real_service->getNotificationsForUserId(userId);
	std::vector<FeedbackNotification> vect;
	for (int i = 0; i < feedbackOatpp->size(); i++) {
		FeedbackNotification feedback;
		fromDtoToFeedbackNotification(feedbackOatpp[i], &feedback);
		vect.push_back(feedback);
	}
	notifications = &vect[0];
}

void FeedbackServiceMapper::deleteReadNotifications() {
	m_real_service->deleteReadNotifications();
}

