#include <Http/Server/HttpServer.h>

namespace tor
{

    HttpServer::HttpServer(std::uint16_t port = 80)
        : m_socket(port)
    {

    }

    HttpServer::~HttpServer()
    {

    }

}