#include "public/feedback/EOP_feedback_FeedbackService.h"
#include "public/feedback/EOP_feedback_FeedbackService.hpp"
#include <iostream>

oatpp::Object<FeedbackDto> FeedbackServiceMapper::mapToOatppFeedback(const Feedback* dto) {
	oatpp::Object<FeedbackDto> feedbackDto;

	feedbackDto->id = dto->id;
	feedbackDto->commentatorUserId = dto->commentatorUserId;
	feedbackDto->commentatorLogin = dto->commentatorLogin;
	feedbackDto->showCommentatorLogin = dto->showCommentatorLogin;
	feedbackDto->courseId = dto->courseId;
	feedbackDto->ownerCourseUserId = dto->ownerCourseUserId;
	feedbackDto->isReadByOwnerCourse = dto->isReadByOwnerCourse;
	feedbackDto->ownerCourseAnswerComment = dto->ownerCourseAnswerComment;
	feedbackDto->ownerCourseAnswerCommentCreationDate = dto->ownerCourseAnswerCommentCreationDate;
	feedbackDto->description = dto->description;
	feedbackDto->creationDate = dto->creationDate;
	feedbackDto->updateDate = dto->updateDate;
	feedbackDto->isBanned = dto->isBanned;
	feedbackDto->banDescription = dto->banDescription;
	feedbackDto->banDate = dto->banDate;
	return feedbackDto;
}

void FeedbackServiceMapper::fromDtoToFeedback(const oatpp::Object<FeedbackDto>& dto, Feedback* feedback) {
	feedback->id = dto->id;
	feedback->commentatorUserId = (char*)dto->commentatorUserId->c_str();
	feedback->commentatorLogin = (char*)dto->commentatorLogin->c_str();
	feedback->showCommentatorLogin = dto->showCommentatorLogin ? 1 : 0;
	feedback->courseId = (char*)dto->courseId->c_str();
	feedback->ownerCourseUserId = (char*)dto->ownerCourseUserId->c_str();
	feedback->isReadByOwnerCourse = dto->isReadByOwnerCourse ? 1 : 0;
	feedback->ownerCourseAnswerComment = (char*)dto->ownerCourseAnswerComment->c_str();
	feedback->ownerCourseAnswerCommentCreationDate = (char*)dto->ownerCourseAnswerCommentCreationDate->c_str();
	feedback->description = (char*)dto->description->c_str();
	feedback->creationDate = (char*)dto->creationDate->c_str();
	feedback->updateDate = (char*)dto->updateDate->c_str();
	feedback->isBanned = dto->isBanned ? 1 : 0;
	feedback->banDescription = (char*)dto->banDescription->c_str();
	feedback->banDate = (char*)dto->banDate->c_str();
}
 
void FeedbackServiceMapper::createFeedback(Feedback* feedback, Feedback* newFeedback)
{
	auto mappedObject = FeedbackServiceMapper::mapToOatppFeedback(feedback);
	auto feedbackOatpp = m_real_service->createFeedback(mappedObject);
	FeedbackServiceMapper::fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::updateFeedback(Feedback* feedback, Feedback* newFeedback)
{
	auto mappedObject = mapToOatppFeedback(feedback);
	auto feedbackOatpp = m_real_service->updateFeedback(mappedObject);
	fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::changeFeedbackLoginVisibility(Feedback* feedback, Feedback* newFeedback)
{
	auto mappedObject = mapToOatppFeedback(feedback);
	auto feedbackOatpp = m_real_service->changeFeedbackLoginVisibility(mappedObject);
	fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::getFeedbackById(int feedbackId, Feedback* feedback)
{
	auto feedbackOatpp = m_real_service->getFeedbackById(feedbackId);
	fromDtoToFeedback(feedbackOatpp, feedback);
}

void FeedbackServiceMapper::getFeedbacks(int offset, int limit, Feedback* feedbacks)
{
	auto feedbackOatpp = m_real_service->getFeedbacks(offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void FeedbackServiceMapper::getFeedbackByUserId(char* userId, int offset, int limit, Feedback* feedbacks)
{
	auto feedbackOatpp = m_real_service->getFeedbackByUserId(userId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void FeedbackServiceMapper::getFeedbackByCourseId(char* courseId, int offset, int limit, Feedback* feedbacks)
{
	auto feedbackOatpp = m_real_service->getFeedbackByCourseId(courseId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void FeedbackServiceMapper::getFeedbackByCourseOwner(char* ownerCourseUserId, int offset, int limit, Feedback* feedbacks)
{
	auto feedbackOatpp = m_real_service->getFeedbackByCourseOwner(ownerCourseUserId, offset, limit);
	std::vector<Feedback> vect;
	for (int i = 0; i < feedbackOatpp->items->size(); i++) {
		Feedback feedback;
		fromDtoToFeedback(feedbackOatpp->items[i], &feedback);
		vect.push_back(feedback);
	}
	feedbacks = &vect[0];
}

void FeedbackServiceMapper::updateAnswerByCourseOwner(Feedback* feedback, Feedback* newFeedback)
{
	auto mappedObject = mapToOatppFeedback(feedback);
	auto feedbackOatpp = m_real_service->updateAnswerByCourseOwner(mappedObject);
	fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::banFeedback(Feedback* feedback, Feedback* newFeedback)
{
	auto mappedObject = mapToOatppFeedback(feedback);
	auto feedbackOatpp = m_real_service->banFeedback(mappedObject);
	fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::unbanFeedback(int feedbackId, Feedback* newFeedback)
{
	auto feedbackOatpp = m_real_service->unbanFeedback(feedbackId);
	fromDtoToFeedback(feedbackOatpp, newFeedback);
}

void FeedbackServiceMapper::deleteFeedback(int feedbackId)
{
	auto feedbackOatpp = m_real_service->deleteFeedback(feedbackId);
}







