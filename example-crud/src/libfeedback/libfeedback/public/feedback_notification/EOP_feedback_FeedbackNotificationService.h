#ifndef Feedback_H
#define Feedback_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int id;
    int feedbackId;
    char* userId;
    char* description;
    int notificationStatus;
    char* creationDate;
} FeedbackNotification;

void createNotificationFeedback(FeedbackNotification*  , FeedbackNotification*  );
void getNotificationById(int id, FeedbackNotification*  );
void readNotificationFeedback(int id, FeedbackNotification*  );
void getNotificationsForUserId(char* userId, FeedbackNotification*  );
void deleteReadNotifications();


#ifdef __cplusplus
}
#endif

#endif 