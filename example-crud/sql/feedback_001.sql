 


create table feedback
(
    id                                        integer primary key,
    description                               varchar(1000)          ,
    commentator_user_id                       varchar(100)                    ,
    commentator_login                         varchar(100)           ,
    show_commentator_login                    boolean                  ,
    course_id                                 varchar(100)                   ,
    owner_course_user_id                      varchar(100)                   ,
    owner_course_answer_comment               varchar(1000),
    owner_course_answer_comment_creation_date varchar(100),
    creation_date                             varchar(100),
    update_date                               varchar(100),
    is_banned                                 boolean                         ,
    is_banned_description                     varchar(1000),
    is_banned_date                            varchar(100)
);
 
create table notification_read_status
(
    id   integer primary key,
    name varchar(50)
);

 

insert into  notification_read_status (id, name)
values (1, 'Не прочитан'),
       (2, 'Прочитан');


create table  feedback_notification
(
    id            INTEGER PRIMARY KEY,
    feedback_id   integer  ,
    user_id       varchar(100)                                                   ,
    description   varchar(100)                                            ,
    read_status   integer  ,
    creation_date varchar(100)
);


 