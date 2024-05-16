
#ifndef AppComponent_hpp
#define AppComponent_hpp

#include "SwaggerComponent.hpp"
#include "DatabaseComponent.hpp"

#include "ErrorHandler.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/core/macro/component.hpp"

/**
 *  Class which creates and holds Application components and registers components in oatpp::base::Environment
 *  Order of components initialization is from top to bottom
 */
class AppComponent {
public:

	/**
	 *  Swagger component
	 */
	SwaggerComponent swaggerComponent;

	/**
	 * Database component
	 */
	DatabaseComponent databaseComponent;

	/**
	 * Create ObjectMapper component to serialize/deserialize DTOs in Controller's API
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
		auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
		objectMapper->getDeserializer()->getConfig()->allowUnknownFields = false;
		return objectMapper;
		}());

	/**
	 *  Create ConnectionProvider component which listens on the port
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, serverConnectionProvider)([] {
		return oatpp::network::tcp::server::ConnectionProvider::createShared({ "0.0.0.0", 8000, oatpp::network::Address::IP_4 });
		}());

	/**
	 *  Create Router component
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, httpRouter)([] {
		return oatpp::web::server::HttpRouter::createShared();
		}());

	/**
	 *  Create ConnectionHandler component which uses Router component to route requests
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, serverConnectionHandler)([] {

		OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router); // get Router component
		OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper); // get ObjectMapper component

		auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);
		connectionHandler->setErrorHandler(std::make_shared<ErrorHandler>(objectMapper));
		return connectionHandler;

		}());

	OATPP_CREATE_COMPONENT(oatpp::Object<ConfigDto>, config)([this] {

		const char* configPath = CONFIG_PATH;
		auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

		oatpp::String configText = oatpp::String::loadFromFile(configPath);
		if (configText) {

			auto profiles = objectMapper->readFromString<oatpp::Fields<oatpp::Object<ConfigDto>>>(configText);

			const char* profileArg = std::getenv("CONFIG_PROFILE"); // first read from env variable
			if (profileArg == nullptr) {
				profileArg = m_cmdArgs.getNamedArgumentValue("--profile", "dev"); // if no env varioable get from command line
			}

			OATPP_LOGD("Server", "Loading configuration profile '%s'", profileArg);

			auto profile = profiles.getValueByKey(profileArg, nullptr);
			if (!profile) {
				throw std::runtime_error("No configuration profile found. Server won't run.");
			}
			return profile;

		}

		OATPP_LOGE("AppComponent", "Can't load configuration file at path '%s'", configPath);
		throw std::runtime_error("[AppComponent]: Can't load configuration file");

		}());

};

#endif /* AppComponent_hpp */
