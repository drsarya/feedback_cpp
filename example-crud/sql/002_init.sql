create table Feedback
(
    id                                   INTEGER PRIMARY KEY,
    description                          varchar(1000) not null,
    commentatorUserId                    varchar(30)   not null,
    commentatorLogin                     varchar(100)  not null,
    showCommentatorLogin                 boolean       not null,
    courseId                             varchar(30)   not null,
    ownerCourseUserId                    varchar(30)   not null,
    ownerCourseAnswerComment             varchar(1000),
    ownerCourseAnswerCommentCreationDate DATETIME,
    creationDate                         DATETIME      not null default CURRENT_TIMESTAMP,
    updateDate                           DATETIME,
    isBanned                             boolean                default false,
    banDescription                       varchar(1000),
    banDate                              DATETIME
);

create table NotificationReadStatus
(
    id   integer primary key,
    name varchar(50)
);


insert into NotificationReadStatus (id, name)
values (1, 'Не прочитан'),
       (2, 'Прочитан');


create table FeedbackNotification
(
    id                 INTEGER PRIMARY KEY,
    feedbackId         integer      not null references Feedback (id) on delete cascade,
    userId             VARCHAR(30)  not null,
    description        varchar(100) not null,
    notificationStatus integer      not null references NotificationReadStatus (id) default 1,
    creationDate       DATETIME     not null                                        default CURRENT_TIMESTAMP
);



