
#ifndef CRUD_FEEDBACKSERVICE_HPP
#define CRUD_FEEDBACKSERVICE_HPP

#include "db/EOP_feedback_FeedbackDb.hpp"
#include "dto/EOP_feedback_FeedbackDto.hpp"
#include "dto/StatusDto.hpp"
#include "dto/PageDto.hpp"
#include "db/EOP_feedback_FeedbackNotificationDb.hpp"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class FeedbackService {
private:
	typedef oatpp::web::protocol::http::Status Status;
private:
	OATPP_COMPONENT(std::shared_ptr<FeedbackDb>, m_database); // Inject database component
public:

	oatpp::Object<FeedbackDto> createFeedback(const oatpp::Object<FeedbackDto>& dto);
	oatpp::Object<FeedbackDto> updateFeedback(const oatpp::Object<FeedbackDto>& dto);
	oatpp::Object<FeedbackDto> changeFeedbackLoginVisibility(const oatpp::Object<FeedbackDto>& dto);

	oatpp::Object<FeedbackDto> getFeedbackById(const oatpp::Int32& feedbackId);
	oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> getFeedbacks(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
	oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> getFeedbackByUserId(const oatpp::String& userId, const oatpp::UInt32& offset, const oatpp::UInt32& limit);
	oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> getFeedbackByCourseId(const oatpp::String& courseId, const oatpp::UInt32& offset, const oatpp::UInt32& limit);
	oatpp::Object<PageDto<oatpp::Object<FeedbackDto>>> getFeedbackByCourseOwner(const oatpp::String& ownerCourseUserId, const oatpp::UInt32& offset, const oatpp::UInt32& limit);

	oatpp::Object<FeedbackDto> updateAnswerByCourseOwner(const oatpp::Object<FeedbackDto>& dto);

	oatpp::Object<FeedbackDto> banFeedback(const oatpp::Object<FeedbackDto>& dto);
	oatpp::Object<FeedbackDto> unbanFeedback(const oatpp::Int32& feedbackId);

	oatpp::Object<StatusDto> deleteFeedback(const oatpp::Int32& feedbackId);

};

#endif //CRUD_FEEDBACKSERVICE_HPP
