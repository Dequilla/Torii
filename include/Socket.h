#pragma once

#include <netinet/in.h>
#include <cstdint>
#include <string>

#define MAX_BUFFER_SIZE 1024

namespace tor 
{

    class Socket 
    {
        short m_port = -1;
        int m_sockfd, m_newsockfd;
        socklen_t m_clilen;
        sockaddr_in m_serv_addr, m_cli_addr;

    public:
        Socket(std::uint16_t port);
        ~Socket();

        void Accept();
        std::string Read();
        void Write(const std::string& msg);
    };

}