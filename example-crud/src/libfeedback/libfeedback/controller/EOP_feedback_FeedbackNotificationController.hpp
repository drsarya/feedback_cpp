
#ifndef FEEDBACKNOTIFICATIONCONTROLLER_HPP
#define FEEDBACKNOTIFICATIONCONTROLLER_HPP

#include "service/EOP_feedback_FeedbackNotificationService.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * FeedbackNotification REST controller.
 */
class FeedbackNotificationController : public oatpp::web::server::api::ApiController {
public:
    FeedbackNotificationController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper)
    {}
private:
    FeedbackNotificationService m_feedbackNotificationService;  
public:

    static std::shared_ptr<FeedbackNotificationController> createShared(
        OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
    ) {
        return std::make_shared<FeedbackNotificationController>(objectMapper);
    }

     
    ENDPOINT_INFO(createNotificationFeedback) {
        info->summary = "Create notification feedback";

        info->addConsumes<Object<FeedbackNotificationDto>>("application/json");

        info->addResponse<Object<FeedbackNotificationDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("POST", "notification-feedback", createNotificationFeedback,
        BODY_DTO(Object<FeedbackNotificationDto>, dto))
    {
        return createDtoResponse(Status::CODE_200, m_feedbackNotificationService.createNotificationFeedback(dto));
    }
 

    ENDPOINT_INFO(readNotificationFeedback) {
        info->summary = "Read notification feedback";

        info->addResponse<Object<FeedbackNotificationDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["id"].description = "Notification Identifier";
    }
    ENDPOINT("PUT", "notification-feedback/{id}", readNotificationFeedback,
        PATH(Int32, id))
    {
        return createDtoResponse(Status::CODE_200, m_feedbackNotificationService.readNotificationFeedback(id));
    }


     ENDPOINT_INFO(getNotificationsForUserId) {
        info->summary = "Get notifications by userId";

        info->addResponse<oatpp::Vector<Object<FeedbackNotificationDto>>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_404, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");

        info->pathParams["userId"].description = "User Identifier";
    }
    ENDPOINT("GET", "notification-feedback/{userId}", getNotificationsForUserId,
        PATH(String, userId))
    {
        return createDtoResponse(Status::CODE_200, m_feedbackNotificationService.getNotificationsForUserId(userId));
    }

 

    ENDPOINT_INFO(deleteReadNotifications) {
        info->summary = "Delete read notifications";

        info->addResponse<Object<StatusDto>>(Status::CODE_200, "application/json");
        info->addResponse<Object<StatusDto>>(Status::CODE_500, "application/json");
    }
    ENDPOINT("DELETE", "notification-feedback/read", deleteReadNotifications )
    {
        return createDtoResponse(Status::CODE_200, m_feedbackNotificationService.deleteReadNotifications());
    }
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* FEEDBACKNOTIFICATIONCONTROLLER_HPP */
