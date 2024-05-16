#include "EOP_feedback_FeedbackNotificationService.hpp"



oatpp::Object<FeedbackNotificationDto> FeedbackNotificationService::createNotificationFeedback(const oatpp::Object<FeedbackNotificationDto>& dto) {

	auto dbResult = m_database->createNotificationFeedback(dto);
	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

	auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackNotificationDto>>>();
	OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
	return result[0];
}


oatpp::Object<FeedbackNotificationDto> FeedbackNotificationService::getNotificationById(const oatpp::Int32& id) {

	auto dbResult = m_database->getNotificationById(id);
	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
	OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Notification not found");

	auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackNotificationDto>>>();
	OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

	return result[0];
}


oatpp::Object<FeedbackNotificationDto> FeedbackNotificationService::readNotificationFeedback(const oatpp::Int32& id) {

	auto dbResult = m_database->readNotificationFeedback(id);
	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
	return FeedbackNotificationService::getNotificationById(id);
}


oatpp::Vector<oatpp::Object<FeedbackNotificationDto>> FeedbackNotificationService::getNotificationsForUserId(const oatpp::String& userId) {

	auto dbResult = m_database->getNotificationsForUserId(userId);
	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

	auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackNotificationDto>>>();
	return items;
}


oatpp::Object<StatusDto> FeedbackNotificationService::deleteReadNotifications() {
	auto dbResult = m_database->deleteReadNotifications();
	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
	auto status = StatusDto::createShared();
	status->status = "OK";
	status->code = 200;
	status->message = "Read notifications was successfully deleted";
	return status;
}

