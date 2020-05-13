#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
  perror(msg);
  exit(1);
}

/*
    Based on: http://www.linuxhowtos.org/C_C++/socket.htm
*/

int main(int argc, char** argv)
{
    int port = 8080;
    int sockfd, newsockfd, resultLength;
    socklen_t clilen;
    char buffer[256];
    sockaddr_in serv_addr, cli_addr;

    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Get port from args
    port = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    // Listen to maximum of 5 connections in queue
    listen(sockfd, 5);

    // Accept requests
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    bzero(buffer,256);
    resultLength = read(newsockfd,buffer,255);
    if (resultLength < 0) error("ERROR reading from socket");
    printf("Here is the message: %s",buffer);

    resultLength = write(newsockfd,"I got your message",18);
    if (resultLength < 0) error("ERROR writing to socket");

    return 0;
}