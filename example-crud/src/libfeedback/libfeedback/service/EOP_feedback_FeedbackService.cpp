 #include "EOP_feedback_FeedbackService.hpp"



 oatpp::Object<FeedbackDto> FeedbackService::createFeedback(const oatpp::Object<FeedbackDto>& dto) {

 	auto dbResult = m_database->createFeedback(dto);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");
    return result[0];

 }

 oatpp::Object<FeedbackDto> FeedbackService::updateFeedback(const oatpp::Object<FeedbackDto>& dto) {

 	auto dbResult = m_database->updateFeedback(dto);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	return FeedbackService::getFeedbackById(dto->id);

 }

 oatpp::Object<FeedbackDto> FeedbackService::changeFeedbackLoginVisibility(const oatpp::Object<FeedbackDto>& dto) {

 	auto dbResult = m_database->changeFeedbackLoginVisibility(dto);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	return FeedbackService::getFeedbackById(dto->id);

 }

 oatpp::Object<FeedbackDto> FeedbackService::getFeedbackById(const oatpp::Int32& id) {

 	auto dbResult = m_database->getFeedbackById(id);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Feedback not found");

 	auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();
 	OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

 	return result[0];

 }

 oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> FeedbackService::getFeedbacks(const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

 	oatpp::UInt32 countToFetch = limit;

 	if (limit > 10) {
 		countToFetch = 10;
 	}

 	auto dbResult = m_database->getFeedbacks(offset, countToFetch);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

 	auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();

 	auto page = PageDto<oatpp::Object<FeedbackDto>>::createShared();
 	page->offset = offset;
 	page->limit = countToFetch;
 	page->count = items->size();
 	page->items = items;

 	return page;

 }

 

 oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> FeedbackService::getFeedbackByUserId(const oatpp::String& userId, const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

 	oatpp::UInt32 countToFetch = limit;

 	if (limit > 10) {
 		countToFetch = 10;
 	}

 	auto dbResult = m_database->getFeedbackByUserId(userId, offset, countToFetch);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

 	auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();

 	auto page = PageDto<oatpp::Object<FeedbackDto>>::createShared();
 	page->offset = offset;
 	page->limit = countToFetch;
 	page->count = items->size();
 	page->items = items;

 	return page;

 }

 oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> FeedbackService::getFeedbackByCourseId(const oatpp::String& courseId, const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

 	oatpp::UInt32 countToFetch = limit;

 	if (limit > 10) {
 		countToFetch = 10;
 	}

 	auto dbResult = m_database->getFeedbackByCourseId(courseId, offset, countToFetch);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

 	auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();

 	auto page = PageDto<oatpp::Object<FeedbackDto>>::createShared();
 	page->offset = offset;
 	page->limit = countToFetch;
 	page->count = items->size();
 	page->items = items;

 	return page;

 }

 oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> FeedbackService::getFeedbackByCourseOwner(const oatpp::String& ownerCourseUserId, const oatpp::UInt32& offset, const oatpp::UInt32& limit) {

 	oatpp::UInt32 countToFetch = limit;

 	if (limit > 10) {
 		countToFetch = 10;
 	}

 	auto dbResult = m_database->getFeedbackByCourseOwner(ownerCourseUserId, offset, countToFetch);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

 	auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<FeedbackDto>>>();

 	auto page = PageDto<oatpp::Object<FeedbackDto>>::createShared();
 	page->offset = offset;
 	page->limit = countToFetch;
 	page->count = items->size();
 	page->items = items;

 	return page;

 }


 oatpp::Object<FeedbackDto> FeedbackService::updateAnswerByCourseOwner(const oatpp::Object<FeedbackDto>& dto) {

 	auto dbResult = m_database->updateAnswerByCourseOwner(dto);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	return getFeedbackById(dto->id);

 }

 oatpp::Object<FeedbackDto> FeedbackService::banFeedback(const oatpp::Object<FeedbackDto>& dto) {

 	auto dbResult = m_database->banFeedback(dto);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	return getFeedbackById(dto->id);

 }

 oatpp::Object<FeedbackDto> FeedbackService::unbanFeedback(const oatpp::Int32& feedbackId) {

 	auto dbResult = m_database->unbanFeedback(feedbackId);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	return getFeedbackById(feedbackId);

 }

 oatpp::Object<StatusDto> FeedbackService::deleteFeedback(const oatpp::Int32& feedbackId) {
 	auto dbResult = m_database->deleteFeedback(feedbackId);
 	OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
 	auto status = StatusDto::createShared();
 	status->status = "OK";
 	status->code = 200;
 	status->message = "Feedback was successfully deleted";
 	return status;
 }