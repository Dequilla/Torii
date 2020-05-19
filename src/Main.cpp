#include <Socket.h>
#include <Http/HttpVersion.h>
#include <Http/HttpMethod.h>
#include <Http/Uri.h>

#include <string>
#include <iostream>

#include <Http/Uri.h>

/*
    Based on:           http://www.linuxhowtos.org/C_C++/socket.htm
    Test with telnet:   https://netbeez.net/blog/telnet-to-test-connectivity-to-tcp/
*/

int main(int argc, char** argv)
{
    std::cout << tor::Uri(tor::Authority("localhost"), tor::Path("/user/1")) << std::endl;
    std::cout << "Equal: " << (tor::Path("/user/:id/test/:function").Compare(tor::Path("/user/mbn2jsn2kjh3n2jh1/test/show")) ? "true" : "false") << std::endl;
    std::cout << tor::Path("/").ToString().GetSource().size() << std::endl;

    tor::Socket socket(8080);
    socket.Accept();

    while(true) {
        std::string str = socket.Read();
        std::cout << "Recieved: " << str << std::endl;  
        socket.Write("HTTP/1.1 200 OK\nContent-Length: 21\nContent-Type: text/html\n\n<h1>Hello world!</h1>\n");
    }

    return 0;
}