create database feedback;

create schema feedback;

create table feedback.feedback
(
    id                                        serial primary key,
    description                               varchar(1000)            not null,
    commentator_user_id                       uuid                     not null,
    commentator_login                         varchar(100)             not null,
    show_commentator_login                    boolean                  not null,
    course_id                                 uuid                     not null,
    owner_course_user_id                      uuid                     not null,
    owner_course_answer_comment               varchar(1000),
    owner_course_answer_comment_creation_date timestamp with time zone,
    creation_date                             timestamp with time zone not null default now(),
    update_date                               timestamp with time zone,
    is_banned                                 boolean                           default false,
    is_banned_description                     varchar(1000),
    is_banned_date                            timestamp with time zone
);

comment on column feedback.feedback.id is 'Идентификатор обратной связи';
comment on column feedback.feedback.description is 'Текст обратной связи';
comment on column feedback.feedback.commentator_user_id is 'Идентификатор комментатора';
comment on column feedback.feedback.commentator_login is 'Логин комментатора';
comment on column feedback.feedback.show_commentator_login is 'Отображать логин комментатора в публикации';
comment on column feedback.feedback.course_id is 'Идентификатор курса, к которому добавлена обратная связь';
comment on column feedback.feedback.owner_course_user_id is 'Идентификатор создателя курса';
comment on column feedback.feedback.owner_course_answer_comment is 'Комментарий создателя курса';
comment on column feedback.feedback.owner_course_answer_comment_creation_date is 'Дата создания комментария от создателя курса';
comment on column feedback.feedback.creation_date is 'Дата создания обратной связи';
comment on column feedback.feedback.update_date is 'Дата обновления обратной связи';
comment on column feedback.feedback.is_banned is 'Заблокирован ли комментарий пользователя';
comment on column feedback.feedback.is_banned_description is 'Причина блокировки комментария';
comment on column feedback.feedback.is_banned_date is 'Дата блокировки комментария';



create table feedback.notification_read_status
(
    id   integer primary key,
    name varchar(50)
);

comment on column feedback.notification_read_status.id is 'Идентификатор статуса прочтения';
comment on column feedback.notification_read_status.name is 'Название статуса';

insert into feedback.notification_read_status (id, name)
values (1, 'Не прочитан'),
       (2, 'Прочитан');


create table feedback.feedback_notification
(
    id            serial primary key,
    feedback_id   integer references feedback.feedback (id)                 not null,
    user_id       uuid                                                      not null,
    is_sent       boolean                                                   not null default false,
    read_status   integer references feedback.notification_read_status (id) not null default 1,
    creation_date timestamp with time zone                                  not null default now()
);


comment on column feedback.feedback_notification.id is 'Идентификатор уведомления';
comment on column feedback.feedback_notification.feedback_id is 'Идентификатор обратной связи';
comment on column feedback.feedback_notification.user_id is 'Идентификатор пользователя для уведомления';
comment on column feedback.feedback_notification.is_sent is 'Отправлено ли уведомление';
comment on column feedback.feedback_notification.read_status is 'Статус прочтения уведомления';
comment on column feedback.feedback_notification.creation_date is 'Дата создания уведомления';

-- права на таблицы

CREATE USER feedback_admin WITH PASSWORD 'admin';
GRANT CONNECT ON DATABASE feedback TO feedback_admin;
GRANT USAGE ON SCHEMA feedback TO feedback_admin;
GRANT SELECT, INSERT, UPDATE, DELETE ON feedback.feedback TO feedback_admin;
GRANT SELECT ON feedback.notification_read_status TO feedback_admin;
GRANT INSERT, UPDATE, DELETE ON feedback.feedback_notification TO feedback_admin;

-- Проверка прав
SELECT pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'SELECT')     AS "SELECT",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'INSERT')     AS "INSERT",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'UPDATE')     AS "UPDATE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'DELETE')     AS "DELETE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'TRUNCATE')   AS "TRUNCATE",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'REFERENCES') AS "REFERENCES",
       pg_catalog.has_table_privilege(
               'feedback_admin', 'feedback.feedback', 'TRIGGER')    AS "TRIGGER";