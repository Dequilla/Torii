#pragma once

#include <netinet/in.h>

namespace tor 
{

    class Socket 
    {
        short m_port = -1;
        char* m_buffer[256];
        int sockfd, newsockfd, resultLength;
        socklen_t clilen;
        sockaddr_in serv_addr, cli_addr;

    public:
        Socket(short port);

        void Listen();
    };

}