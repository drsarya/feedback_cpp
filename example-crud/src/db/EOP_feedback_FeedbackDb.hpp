
 #ifndef CRUD_FeedbackDb_HPP
 #define CRUD_FeedbackDb_HPP

 #include "dto/EOP_feedback_FeedbackDto.hpp"
 #include "oatpp-sqlite/orm.hpp"

 #include OATPP_CODEGEN_BEGIN(DbClient) //<- Begin Codegen

 /**
  * FeedbackDb client definitions.
  */
 class FeedbackDb : public oatpp::orm::DbClient {
 public:

 	FeedbackDb(const std::shared_ptr<oatpp::orm::Executor>& executor)
 		: oatpp::orm::DbClient(executor)
 	{


 	}

 	QUERY(createFeedback,
 		"insert into Feedback(description, commentatorUserId, commentatorLogin, showCommentatorLogin, courseId, ownerCourseUserId ) values "
 		"(:feedback.description, :feedback.commentatorUserId, :feedback.commentatorLogin, :feedback.showCommentatorLogin, :feedback.courseId, :feedback.ownerCourseUserId);",
 		PARAM(oatpp::Object<FeedbackDto>, feedback))

 		QUERY(updateFeedback,
 			"UPDATE Feedback "
 			"SET updateDate = CURRENT_TIMESTAMP, "
 			"description = :feedback.description "
 			"WHERE  id=:feedback.id;",
 			PARAM(oatpp::Object<FeedbackDto>, feedback))

 		QUERY(changeFeedbackLoginVisibility,
 			"UPDATE Feedback "
 			"SET updateDate = CURRENT_TIMESTAMP, "
 			"showCommentatorLogin = :feedback.showCommentatorLogin "
 			"WHERE  id=:feedback.id;",
 			PARAM(oatpp::Object<FeedbackDto>, feedback))


 		QUERY(getFeedbacks,
 			"SELECT * FROM Feedback order by creationDate desc LIMIT :limit OFFSET :offset;",
 			PARAM(oatpp::UInt32, offset),
 			PARAM(oatpp::UInt32, limit))

 		QUERY(getFeedbackById,
 			"SELECT * FROM Feedback WHERE id=:feedbackId ;",
 			PARAM(oatpp::Int32, feedbackId) )

 		QUERY(getFeedbackByUserId,
 			"SELECT * FROM Feedback WHERE commentatorUserId=:userId order by creationDate desc LIMIT :limit OFFSET :offset;",
 			PARAM(oatpp::String, userId),
 			PARAM(oatpp::UInt32, offset),
 			PARAM(oatpp::UInt32, limit))

 		QUERY(getFeedbackByCourseId,
 			"SELECT * FROM Feedback where courseId=:courseId and isBanned=false and isReadByOwnerCourse=true order by creationDate desc LIMIT :limit OFFSET :offset;",
 			PARAM(oatpp::String, courseId),
 			PARAM(oatpp::UInt32, offset),
 			PARAM(oatpp::UInt32, limit))

 		QUERY(getFeedbackByCourseOwner,
 			"SELECT * FROM Feedback where ownerCourseUserId=:ownerCourseUserId order by creationDate desc LIMIT :limit OFFSET :offset;",
 			PARAM(oatpp::String, ownerCourseUserId),
 			PARAM(oatpp::UInt32, offset),
 			PARAM(oatpp::UInt32, limit))

 		QUERY(updateAnswerByCourseOwner,
 			"UPDATE Feedback "
 			"SET ownerCourseAnswerComment =:feedback.ownerCourseAnswerComment, "
 			"ownerCourseAnswerCommentCreationDate = CURRENT_TIMESTAMP, "
 			"isReadByOwnerCourse=:feedback.isReadByOwnerCourse "
 			"WHERE id=:feedback.id;",
 			PARAM(oatpp::Object<FeedbackDto>, feedback))

 		QUERY(banFeedback,
 			"UPDATE Feedback "
 			"SET isBanned = true, "
 			"banDescription =:feedback.banDescription, "
 			"banDate = CURRENT_TIMESTAMP "
 			"WHERE id = :feedback.id;",
 			PARAM(oatpp::Object<FeedbackDto>, feedback))

 		QUERY(unbanFeedback,
 			"UPDATE  Feedback "
 			"SET isBanned = false, "
 			"banDescription = null, "
 			"banDate = null "
 			"WHERE id=:feedbackId;",
 			PARAM(oatpp::Int32, feedbackId))


 		QUERY(deleteFeedback,
 			"DELETE FROM  Feedback WHERE id=:feedbackId;",
 			PARAM(oatpp::Int32, feedbackId))

 };

 #include OATPP_CODEGEN_END(DbClient) //<- End Codegen

 #endif //CRUD_FEEDBACKDB_HPP
