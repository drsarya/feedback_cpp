create table feedback
(
    id                                        INTEGER PRIMARY KEY,
    description                               varchar(1000) not null,
    commentator_user_id                       varchar(30)   not null,
    commentator_login                         varchar(100)  not null,
    show_commentator_login                    boolean       not null,
    course_id                                 varchar(30)   not null,
    is_read_by_owner_course                       boolean                  not null default false,
    owner_course_user_id                      varchar(30)   not null,
    is_read_by_owner_course                       boolean              not null default false,
    owner_course_answer_comment               varchar(1000),
    owner_course_answer_comment_creation_date DATETIME,
    creation_date                             DATETIME      not null default CURRENT_TIMESTAMP,
    update_date                               DATETIME,
    is_banned                                 boolean                default false,
    ban_description                           varchar(1000),
    ban_date                                  DATETIME
);


create table notification_read_status
(
    id   integer primary key,
    name varchar(50)
);


insert into notification_read_status (id, name)
values (1, 'Не прочитан'),
       (2, 'Прочитан');


create table feedback_notification
(
    id                  INTEGER PRIMARY KEY,
    feedback_id         integer                                          not null references feedback (id) on delete cascade,
    user_id             varchar(30)                                      not null,
    description         varchar(100)                                     not null,
    notification_status integer references notification_read_status (id) not null default 1,
    creation_date       DATETIME                                         not null default CURRENT_TIMESTAMP
);

 