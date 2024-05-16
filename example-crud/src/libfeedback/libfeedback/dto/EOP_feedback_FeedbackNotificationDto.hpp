#ifndef FeedbackNotificationDto_hpp
#define FeedbackNotificationDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


class FeedbackNotificationDto : public oatpp::DTO {

	DTO_INIT(FeedbackNotificationDto, DTO)

		DTO_FIELD(Int32, id);
	DTO_FIELD(Int32, feedbackId);
	DTO_FIELD(String, userId);
	DTO_FIELD(String, description);
	DTO_FIELD(Int32, notificationStatus);
	DTO_FIELD(String, creationDate);
};


#include OATPP_CODEGEN_END(DTO)

#endif /* FeedbackNotificationDto_hpp */
