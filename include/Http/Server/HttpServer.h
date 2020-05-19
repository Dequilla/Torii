#pragma once
#include <cstdint>

#include <Socket.h>

namespace tor 
{

    class HttpServer
    {
        tor::Socket m_socket;

    public:
        HttpServer(std::uint16_t port = 80);
        ~HttpServer();

        // Use hash tables for routing?
        // Have a router which has the hash table?
        // Allow routers to have routers in them?
    };

}