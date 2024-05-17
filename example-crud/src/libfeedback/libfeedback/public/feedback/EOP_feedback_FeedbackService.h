#ifndef Feedback_H
#define Feedback_H

#ifdef __cplusplus
extern "C" {
#endif

	struct Feedback {
		int id;
		char* commentatorUserId;
		char* commentatorLogin;
		int showCommentatorLogin;
		char* courseId;
		char* ownerCourseUserId;
		int isReadByOwnerCourse;
		char* ownerCourseAnswerComment;
		char* ownerCourseAnswerCommentCreationDate;
		char* description;
		char* creationDate;
		char* updateDate;
		int isBanned;
		char* banDescription;
		char* banDate;
	};

	void createFeedback(struct Feedback*, struct Feedback*);
	void updateFeedback(struct Feedback*, struct  Feedback*);
	void changeFeedbackLoginVisibility(struct Feedback*, struct Feedback*);
	void getFeedbackById(int, struct Feedback*);
	void getFeedbacks(int, int, struct Feedback*);
	void getFeedbackByUserId(char*, int, int, struct Feedback*);
	void getFeedbackByCourseId(char*, int, int, struct Feedback*);
	void getFeedbackByCourseOwner(char*, int, int, struct Feedback*);
	void updateAnswerByCourseOwner(struct  Feedback*, struct  Feedback*);
	void banFeedback(struct Feedback*, struct Feedback*);
	void unbanFeedback(int, struct Feedback*);
	void deleteFeedback(int);


#ifdef __cplusplus
}
#endif

#endif