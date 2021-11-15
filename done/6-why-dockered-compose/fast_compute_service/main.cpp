#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Util/ServerApplication.h"
#include <iostream>
#include <string>

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;

class HelloRequestHandler: public HTTPRequestHandler
{
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
    {
        Application& app = Application::instance();
        
        std::istream& requestDataStream = request.stream();
        std::string requestData(std::istreambuf_iterator<char>(requestDataStream), {});
        int64_t n = std::stoll(requestData);

        app.logger().information("Request data %s", requestData);
        app.logger().information("Request from %s", request.clientAddress().toString());

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        response.send()
          << std::to_string(computeFibonacci(n));
    }

    int64_t computeFibonacci(int64_t n) {
      int64_t result = 0;

      int64_t t1 = 0;
      int64_t t2 = 1;

      while (n > 1) {
        result = t1 + t2;
        t1 = t2;
        t2 = result;
        n--;
      }
      return result;
    }
};

class HelloRequestHandlerFactory: public HTTPRequestHandlerFactory
{
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest&)
    {
        return new HelloRequestHandler;
    }
};

class WebServerApp: public ServerApplication
{
    void initialize(Application& self)
    {
        loadConfiguration();
        ServerApplication::initialize(self);
    }

    int main(const std::vector<std::string>&)
    {
        UInt16 port = static_cast<UInt16>(config().getUInt("port", 8080));

        HTTPServer srv(new HelloRequestHandlerFactory, port);
        srv.start();
        logger().information("HTTP Server started on port %hu.", port);
        waitForTerminationRequest();
        logger().information("Stopping HTTP Server...");
        srv.stop();

        return Application::EXIT_OK;
    }
};

POCO_SERVER_MAIN(WebServerApp)
