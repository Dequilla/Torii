#include <Http/Server/HttpServer.h>

namespace tor
{

    HttpServer::HttpServer(std::uint16_t port)
        : m_socket(port)
    {

    }

    HttpServer::~HttpServer()
    {

    }

    int HttpServer::Listen()
    {
        while(true) {
            // TODO: Do i need to break connections somehow when done?
            m_socket.Accept();

            // 1. Read
            std::string str = m_socket.Read();

            // 2. Parse into HttpRequest

            // 3. Send into middleware chain and get HttpResonse

            // 4. HttpResponse to text and write to socket
            m_socket.Write("HTTP/1.1 200 OK\nContent-Length: 21\nContent-Type: text/html\n\n<h1>Hello world!</h1>\n\n");
        }

        return 0;
    }

}