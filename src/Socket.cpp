#include <Socket.h>

#include <Exception.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h> 
#include <sys/socket.h>

namespace tor {

    Socket::Socket(short port) 
        : m_port(port) 
    {

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            throw tor::BaseException("Could not open socket.");
        
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            throw tor::BaseException("Could not bind socket.");

        // Listen to maximum of 5 connections in queue
        listen(sockfd, 5);
    }

    void Socket::Listen() {
        // Accept requests
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            throw BaseException("Could not accept request.");

        bzero(m_buffer, 256);
        resultLength = read(newsockfd, m_buffer, 255);
        if (resultLength < 0) throw BaseException("Could not read from socket.");
        printf("Here is the message: %s", m_buffer);

        resultLength = write(newsockfd,"I got your message",18);
        if (resultLength < 0) throw BaseException("Could not write to socket.");
    }
    
}