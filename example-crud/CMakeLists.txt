cmake_minimum_required(VERSION 3.1)
project(crud)

set(CMAKE_CXX_STANDARD 11)

add_library(crud-lib
        src/libfeedback/libfeedback/controller/EOP_feedback_FeedbackController.hpp
        src/libfeedback/libfeedback/controller/EOP_feedback_FeedbackNotificationController.hpp
        src/libfeedback/libfeedback/controller/StaticController.hpp
        
        src/libfeedback/libfeedback/db/EOP_feedback_FeedbackDb.hpp
        src/libfeedback/libfeedback/db/EOP_feedback_FeedbackNotificationDb.hpp
        
        src/libfeedback/libfeedback/dto/EOP_feedback_FeedbackDto.hpp
        src/libfeedback/libfeedback/dto/EOP_feedback_FeedbackNotificationDto.hpp
        src/libfeedback/libfeedback/dto/PageDto.hpp
        src/libfeedback/libfeedback/dto/StatusDto.hpp


        src/libfeedback/libfeedback/public/feedback/EOP_feedback_FeedbackService.c
        src/libfeedback/libfeedback/public/feedback/EOP_feedback_FeedbackService.cpp
        src/libfeedback/libfeedback/public/feedback/EOP_feedback_FeedbackService.h
        src/libfeedback/libfeedback/public/feedback/EOP_feedback_FeedbackService.hpp

        src/libfeedback/libfeedback/public/feedback_notification/EOP_feedback_FeedbackNotificationService.c
        src/libfeedback/libfeedback/public/feedback_notification/EOP_feedback_FeedbackNotificationService.cpp
        src/libfeedback/libfeedback/public/feedback_notification/EOP_feedback_FeedbackNotificationService.h
        src/libfeedback/libfeedback/public/feedback_notification/EOP_feedback_FeedbackNotificationService.hpp
        
        src/libfeedback/libfeedback/service/EOP_feedback_FeedbackNotificationService.cpp
        src/libfeedback/libfeedback/service/EOP_feedback_FeedbackNotificationService.hpp
        src/libfeedback/libfeedback/service/EOP_feedback_FeedbackService.cpp
        src/libfeedback/libfeedback/service/EOP_feedback_FeedbackService.hpp
        
        src/libfeedback/libfeedback/AppComponent.hpp
        src/libfeedback/libfeedback/DatabaseComponent.hpp
        src/libfeedback/libfeedback/SwaggerComponent.hpp
        "src/libfeedback/libfeedback/ErrorHandler.cpp"
        src/libfeedback/libfeedback/ErrorHandler.hpp)

## include directories

target_include_directories(crud-lib PUBLIC src/libfeedback/libfeedback)


## link libs

find_package(oatpp          1.3.0 REQUIRED)
find_package(oatpp-swagger  1.3.0 REQUIRED)
find_package(oatpp-sqlite   1.3.0 REQUIRED)

target_link_libraries(crud-lib
        # Oat++
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-sqlite
)



add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

        -DDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/db.sqlite"
        ## SQLite database test file
        -DTESTDATABASE_FILE="${CMAKE_CURRENT_SOURCE_DIR}/test-db.sqlite"

        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
       -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)

if(CMAKE_SYSTEM_NAME MATCHES Linux)
    find_package(Threads REQUIRED)
    target_link_libraries(crud-lib INTERFACE Threads::Threads ${CMAKE_DL_LIBS})
endif()

## add executables

add_executable(crud-exe "src/libfeedback/libfeedback/App.cpp")
target_link_libraries(crud-exe crud-lib)

 

 
