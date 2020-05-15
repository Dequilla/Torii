#include <Socket.h>

#include <Exception.h>
#include <strings.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h> 
#include <sys/socket.h>

#include <iostream>

namespace tor {

    Socket::Socket(short port) 
        : m_port(port) 
    {

        m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (m_sockfd < 0)
            throw tor::BaseException("Could not open socket.");
        
        bzero((char *) &m_serv_addr, sizeof(m_serv_addr));
        m_serv_addr.sin_family = AF_INET;
        m_serv_addr.sin_port = htons(m_port);
        m_serv_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(m_sockfd, (struct sockaddr *) &m_serv_addr, sizeof(m_serv_addr)) < 0)
            throw tor::BaseException("Could not bind socket.");

        // Listen to maximum of 5 connections in queue
        listen(m_sockfd, 5);
    }

    void Socket::Accept() {
        // Accept requests
        m_clilen = sizeof(m_cli_addr);
        m_newsockfd = accept(m_sockfd, (struct sockaddr *) &m_cli_addr, &m_clilen);
        if (m_newsockfd < 0)
            throw BaseException("Could not accept request.");
    }

    std::string Socket::Read() {
        std::string buf;
        char buffer[MAX_BUFFER_SIZE];
        bzero(buffer, MAX_BUFFER_SIZE);
        
        int resultLength = read(m_newsockfd, buffer, MAX_BUFFER_SIZE - 1);
        buf.assign(buffer, resultLength);
        
        if(resultLength < 0) throw BaseException("Could not read from socket.");
        return buf;
    }

    void Socket::Write(const std::string& msg) {
        int resultLength = write(m_newsockfd, &msg[0], msg.length());
        if (resultLength < 0) throw BaseException("Could not write to socket.");
    }

}