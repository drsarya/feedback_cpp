
#ifndef CRUD_PUBLIC_FEEDBACKSERVICE_HPP
#define CRUD_PUBLIC_FEEDBACKSERVICE_HPP

#include "dto/EOP_feedback_FeedbackDto.hpp"
#include "service/EOP_feedback_FeedbackService.hpp"

#include "oatpp/core/macro/component.hpp"

class FeedbackServiceMapper {
private:
	OATPP_COMPONENT(std::shared_ptr<FeedbackService>, m_real_service); // Inject service
public:

	oatpp::Object<FeedbackDto> mapToOatppFeedback(const Feedback* dto);
	void fromDtoToFeedback(const oatpp::Object<FeedbackDto>& dto, Feedback* feedback);

	void createFeedback(Feedback* feedback, Feedback* newFeedback);
	void updateFeedback(Feedback*, Feedback*);
	void changeFeedbackLoginVisibility(Feedback*, Feedback*);
	void getFeedbackById(int, struct Feedback*);
	void getFeedbacks(int offset, int limit, Feedback* feedbacks);
	void getFeedbackByUserId(char* userId, int offset, int limit, Feedback* feedbacks);
	void getFeedbackByCourseId(char* courseId, int offset, int limit, Feedback* feedbacks);
	void getFeedbackByCourseOwner(char* ownerCourseUserId, int offset, int limit, Feedback* feedbacks);

	void updateAnswerByCourseOwner(Feedback* feedback, Feedback* newFeedback);
	void banFeedback(Feedback* feedback, Feedback* newFeedback);
	void unbanFeedback(int feedbackId, Feedback* newFeedback);
	void deleteFeedback(int feedbackId);
};

#endif //CRUD_PUBLIC_FEEDBACKSERVICE_HPP
