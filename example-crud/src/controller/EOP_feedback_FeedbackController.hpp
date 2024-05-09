
// #ifndef FeedbackController_hpp
// #define FeedbackController_hpp

// #include "service/EOP_feedback_FeedbackService.hpp"

// #include "oatpp/web/server/api/ApiController.hpp"
// #include "oatpp/parser/json/mapping/ObjectMapper.hpp"
// #include "oatpp/core/macro/codegen.hpp"

// #include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

// /**
//  * User REST controller.
//  */
// class FeedbackController : public oatpp::web::server::api::ApiController {
// public:
//     FeedbackController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
//         : oatpp::web::server::api::ApiController(objectMapper)
//     {}
// private:
//     FeedbackService m_feedbackService; // Create feedback service.
// public:

//     static std::shared_ptr<FeedbackController> createShared(
//         OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
//     ) {
//         return std::make_shared<FeedbackController>(objectMapper);
//     }
//     /*

//     ENDPOINT_INFO(createFeedback) {
//         info->summary = "Create notificationFeedback";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
//     }
//     ENDPOINT("POST", "feedback", createFeedback,
//         BODY_DTO(Object<FeedbackDto>, userDto))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.createFeedback(userDto));
//     }


//     ENDPOINT_INFO(updateFeedback) {
//         info->summary = "Update feedback by id";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("PUT", "feedback/{feedbackId}", updateFeedback,
//         PATH(Int32, feedbackId),
//         BODY_DTO(Object<FeedbackDto>, dto))
//     {
//         dto->id = feedbackId;
//         return createDtoResponse(Status::CODE_200, m_feedbackService.updateFeedback(dto));
//     }


//     ENDPOINT_INFO(changeFeedbackLoginVisibility) {
//         info->summary = "Update feedback login commentator visibility by feedbackId";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("PUT", "feedback/{feedbackId}/login-visibility", changeFeedbackLoginVisibility,
//         PATH(Int32, userId),
//         BODY_DTO(Object<FeedbackDto>, dto))
//     {
//         dto->id = userId;
//         return createDtoResponse(Status::CODE_200, m_feedbackService.changeFeedbackLoginVisibility(dto));
//     }


//     ENDPOINT_INFO(getFeedbackById) {
//         info->summary = "Get feedback by id";

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("GET", "feedback/{feedbackId}", getFeedbackById,
//         PATH(UInt32, feedbackId))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.getFeedbackById(feedbackId));
//     }


//     ENDPOINT_INFO(getFeedbacks) {
//         info->summary = "get all paged feedback";

//         info->addResponse<oatpp::Object<FeedbackPageDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
//     }
//     ENDPOINT("GET", "feedback/offset/{offset}/limit/{limit}", getFeedbacks,
//         PATH(UInt32, offset),
//         PATH(UInt32, limit))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.getFeedbacks(offset, limit));
//     }


//     ENDPOINT_INFO(getFeedbackByUserId) {
//         info->summary = "get all paged feedback by user id";

//         info->addResponse<oatpp::Object<FeedbackPageDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
//     }
//     ENDPOINT("GET", "feedback/commentators/{userId}/offset/{offset}/limit/{limit}", getFeedbackByUserId,
//         PATH(String, userId),
//         PATH(UInt32, offset),
//         PATH(UInt32, limit))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.getFeedbackByUserId(userId, offset, limit));
//     }


//     ENDPOINT_INFO(getFeedbackByCourseId) {
//         info->summary = "get all paged feedback by course id";

//         info->addResponse<oatpp::Object<FeedbackPageDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
//     }
//     ENDPOINT("GET", "feedback/courses/{courseId}/offset/{offset}/limit/{limit}", getFeedbackByCourseId,
//         PATH(String, courseId),
//         PATH(UInt32, offset),
//         PATH(UInt32, limit))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.getFeedbackByCourseId(courseId, offset, limit));
//     }


//     ENDPOINT_INFO(getFeedbackByCourseOwner) {
//         info->summary = "get all stored users";

//         info->addResponse<oatpp::Object<FeedbackPageDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
//     }
//     ENDPOINT("GET", "feedback/course-owners/{ownerCourseUserId}/offset/{offset}/limit/{limit}", getFeedbackByCourseOwner,
//         PATH(String, ownerCourseUserId),
//         PATH(UInt32, offset),
//         PATH(UInt32, limit))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.getFeedbackByCourseOwner(ownerCourseUserId, offset, limit));
//     }

//     ENDPOINT_INFO(updateAnswerByCourseOwner) {
//         info->summary = "Update course owner response to feedback";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("PUT", "feedback/{feedbackId}/answer", updateAnswerByCourseOwner,
//         PATH(Int32, feedbackId),
//         BODY_DTO(Object<FeedbackDto>, dto))
//     {
//         dto->id = feedbackId;
//         return createDtoResponse(Status::CODE_200, m_feedbackService.updateAnswerByCourseOwner(dto));
//     }



//     ENDPOINT_INFO(banFeedback) {
//         info->summary = "Ban feedback";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("PUT", "feedback/{feedbackId}/ban", banFeedback,
//         PATH(Int32, feedbackId),
//         BODY_DTO(Object<FeedbackDto>, dto))
//     {
//         dto->id = feedbackId;
//         return createDtoResponse(Status::CODE_200, m_feedbackService.banFeedback(dto));
//     }


//     ENDPOINT_INFO(unbanFeedback) {
//         info->summary = "Update User by userId";

//         info->addConsumes<Object<FeedbackDto>>("application/json");

//         info->addResponse<Object<FeedbackDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback identifier";
//     }
//     ENDPOINT("PUT", "feedback/{feedbackId}/unban", unbanFeedback,
//         PATH(Int32, feedbackId) )
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.unbanFeedback(feedbackId));
//     }


//     ENDPOINT_INFO(deleteFeedback) {
//         info->summary = "Delete feedback by id";

//         info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
//         info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

//         info->pathParams["feedbackId"].description = "Feedback Identifier";
//     }
//     ENDPOINT("DELETE", "feedback/{feedbackId}", deleteFeedback,
//         PATH(Int32, feedbackId))
//     {
//         return createDtoResponse(Status::CODE_200, m_feedbackService.deleteFeedback(feedbackId));
//     }
//     */
// };

// #include OATPP_CODEGEN_END(ApiController) //<- End Codegen

// #endif /* UserController_hpp */