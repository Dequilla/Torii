#pragma once
#include <cstdint>

#include <Socket.h>
#include <Http/Server/HttpRouter.h>

namespace tor 
{

    class HttpServer : public HttpRouter
    {
        tor::Socket m_socket;

    public:
        HttpServer(std::uint16_t port = 80);
        ~HttpServer();

        int Listen();

        // Use hash tables for routing?
        // Have a router which has the hash table?
        // Allow routers to have routers in them?
    };

}