
#ifndef CRUD_DATABASECOMPONENT_HPP
#define CRUD_DATABASECOMPONENT_HPP

#include "db/EOP_feedback_FeedbackDb.hpp"
#include "db/EOP_feedback_FeedbackNotificationDb.hpp"

class DatabaseComponent {
public:
    
  /**
   * Create database connection provider component
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::postgresql::Connection>>, dbConnectionProvider)([] {

    /* Create database-specific ConnectionProvider */
      auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>("postgresql://postgres:db-pass@db:5432/postgres");

    /* Create database-specific ConnectionPool */
    return oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
        10 /* max-connections */,
        std::chrono::seconds(5) /* connection TTL */);

  }());
 

  /**
   * Create database client
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<FeedbackNotificatonDb>, feedbackNotificationDb)([] {

      /* Get database ConnectionProvider component */
      OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

      /* Create database-specific Executor */
      auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

      /* Create MyClient database client */
      return std::make_shared<FeedbackNotificatonDb>(executor);

      }());


   /**
    * Create database client
    */
   OATPP_CREATE_COMPONENT(std::shared_ptr<FeedbackDb>, feedbackDb)([] {

       /* Get database ConnectionProvider component */
       OATPP_COMPONENT(std::shared_ptr<oatpp::provider::Provider<oatpp::sqlite::Connection>>, connectionProvider);

       /* Create database-specific Executor */
       auto executor = std::make_shared<oatpp::sqlite::Executor>(connectionProvider);

       /* Create MyClient database client */
       return std::make_shared<FeedbackDb>(executor);

       }());

};

#endif //CRUD_DATABASECOMPONENT_HPP
