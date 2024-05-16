#ifndef FeedbackDto_hpp
#define FeedbackDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


class FeedbackDto : public oatpp::DTO {

	DTO_INIT(FeedbackDto, DTO)

		DTO_FIELD(Int32, id);
	DTO_FIELD(String, commentatorUserId);
	DTO_FIELD(String, commentatorLogin);
	DTO_FIELD(Boolean, showCommentatorLogin);
	DTO_FIELD(String, courseId);
	DTO_FIELD(String, ownerCourseUserId);
	DTO_FIELD(Boolean, isReadByOwnerCourse);
	DTO_FIELD(String, ownerCourseAnswerComment);
	DTO_FIELD(String, ownerCourseAnswerCommentCreationDate);
	DTO_FIELD(String, description);
	DTO_FIELD(String, creationDate);
	DTO_FIELD(String, updateDate);
	DTO_FIELD(Boolean, isBanned);
	DTO_FIELD(String, banDescription);
	DTO_FIELD(String, banDate);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* FeedbackDto_hpp */
