#ifndef FeedbackNotificationDto_hpp
#define FeedbackNotificationDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)


ENUM(FeedbackReadStatus, v_int32,
    VALUE(NOT_READ, 1, "NOT_READ"),
    VALUE(READ, 2, "READ")
)


class FeedbackNotificationDto : public oatpp::DTO {

    DTO_INIT(FeedbackNotificationDto, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(Int32, feedbackId, "feedbackId");
    DTO_FIELD(String, userId, "userId");
    DTO_FIELD(String, description, "description");
    DTO_FIELD(Enum<FeedbackReadStatus>::AsString, notificationStatus, "notificationStatus");
    DTO_FIELD(String, creationDate, "creationDate");
};


#include OATPP_CODEGEN_END(DTO)

#endif /* FeedbackNotificationDto_hpp */
