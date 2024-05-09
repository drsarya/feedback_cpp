
#ifndef CRUD_USERDB_HPP
#define CRUD_USERDB_HPP

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

		oatpp::orm::SchemaMigration migration(executor);
		migration.addFile(1 /* start from version 1 */, DATABASE_MIGRATIONS "/feedback_001.sql");
		// TODO - Add more migrations here.
		migration.migrate(); // <-- run migrations. This guy will throw on error.

		auto version = executor->getSchemaVersion();
		OATPP_LOGD("FeedbackDb", "Migration - OK. Version=%lld.", version);

	}
	QUERY(createFeedback,
		"insert into feedback.feedback(description, commentator_user_id, commentator_login, show_commentator_login, course_id, owner_course_user_id ) values "
		"(:feedback.description, :feedback.commentatorUserId, :feedback.commentatorLogin, :feedback.showCommentatorLogin, :feedback.courseId, :feedback.ownerCourseUserId);",
		PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(updateFeedback,
			"UPDATE feedback.feedback "
			"SET update_date = now(), "
			"description = :feedback.description "
			"WHERE  id=:feedback.id;",
			PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(changeFeedbackLoginVisibility,
			"UPDATE feedback.feedback "
			"SET update_date = now(), "
			"show_commentator_login = :feedback.showCommentatorLogin "
			"WHERE  id=:feedback.id;",
			PARAM(oatpp::Object<FeedbackDto>, feedback))


		QUERY(getFeedbacks,
			"SELECT * FROM feedback.feedback order by creation_date desc LIMIT :limit OFFSET :offset;" )

		QUERY(getFeedbackById,
			"SELECT * FROM feedback.feedback WHERE id=:feedbackId ;",
			PARAM(oatpp::Int32, feedbackId) )

		QUERY(getFeedbackByUserId,
			"SELECT * FROM feedback.feedback WHERE commentator_user_id=:userId order by creation_date desc LIMIT :limit OFFSET :offset;",
			PARAM(oatpp::String, userId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(getFeedbackByCourseId,
			"SELECT * FROM feedback.feedback where course_id=:courseId and is_banned=false order by creation_date desc LIMIT :limit OFFSET :offset;",
			PARAM(oatpp::String, courseId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(getFeedbackByCourseOwner,
			"SELECT * FROM feedback.feedback where owner_course_user_id=:ownerCourseUserId order by creation_date desc LIMIT :limit OFFSET :offset;",
			PARAM(oatpp::String, ownerCourseUserId),
			PARAM(oatpp::UInt32, offset),
			PARAM(oatpp::UInt32, limit))

		QUERY(updateAnswerByCourseOwner,
			"UPDATE feedback.feedback "
			"SET owner_course_answer_comment =:feedback.ownerCourseAnswerComment, "
			"owner_course_answer_comment_creation_date = now()"
			"WHERE id=:feedback.id;",
			PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(banFeedback,
			"UPDATE feedback.feedback "
			"SET is_banned = true, "
			"is_banned_description =:feedback.is_banned_description, "
			"is_banned_date = now() "
			"WHERE id = :feedback.id;",
			PARAM(oatpp::Object<FeedbackDto>, feedback))

		QUERY(unbanFeedback,
			"UPDATE feedback.feedback "
			"SET is_banned = false, "
			"is_banned_description = null, "
			"is_banned_date = null "
			"WHERE id=:feedbackId;",
			PARAM(oatpp::Int32, feedbackId))


		QUERY(deleteFeedback,
			"DELETE FROM feedback.feedback WHERE id=:feedbackId;",
			PARAM(oatpp::Int32, feedbackId))

};

#include OATPP_CODEGEN_END(DbClient) //<- End Codegen

#endif //CRUD_FEEDBACKDB_HPP
