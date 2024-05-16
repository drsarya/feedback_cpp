cmake_minimum_required(VERSION 3.1)
project(crud)

set(CMAKE_CXX_STANDARD 11)

add_library(crud-lib
        src/controller/EOP_feedback_FeedbackController.hpp
        src/controller/EOP_feedback_FeedbackNotificationController.hpp
        src/controller/StaticController.hpp
        
        src/db/EOP_feedback_FeedbackDb.hpp
        src/db/EOP_feedback_FeedbackNotificationDb.hpp
        
        src/dto/EOP_feedback_FeedbackDto.hpp
        src/dto/EOP_feedback_FeedbackNotificationDto.hpp
        src/dto/PageDto.hpp
        src/dto/StatusDto.hpp
        
        src/service/EOP_feedback_FeedbackNotificationService.cpp 
        src/service/EOP_feedback_FeedbackNotificationService.hpp
        src/service/EOP_feedback_FeedbackService.cpp
        src/service/EOP_feedback_FeedbackService.hpp
        
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/SwaggerComponent.hpp
        "src/libfeedback/libfeedback/ErrorHandler.cpp"
        src/ErrorHandler.hpp)

## include directories

target_include_directories(crud-lib PUBLIC src)


## link libs

find_package(oatpp          1.3.0 REQUIRED)
find_package(oatpp-swagger  1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)

target_link_libraries(crud-lib
        # Oat++
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-swagger
        PUBLIC oatpp::oatpp-postgresql
)



add_definitions(
        ## define path to swagger-ui static resources folder
        -DOATPP_SWAGGER_RES_PATH="${oatpp-swagger_INCLUDE_DIRS}/../bin/oatpp-swagger/res"

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

 

 
