#include <Socket.h>
#include <Http/HttpVersion.h>

#include <string>
#include <iostream>

/*
    Based on: http://www.linuxhowtos.org/C_C++/socket.htm
    Test with telnet: https://netbeez.net/blog/telnet-to-test-connectivity-to-tcp/
*/

int main(int argc, char** argv)
{
    std::cout << "Version: " << tor::HttpVersion() << std::endl;

    tor::Socket socket(8080);
    socket.Accept();

    while(true) {
        std::string str = socket.Read();
        std::cout << "Recieved: " << str << std::endl;  
        socket.Write("Recieved your message...");
    }

    return 0;
}