#include <string>
#include <iostream>

#include <Http/Server/HttpServer.h>

/*
    Based on:           http://www.linuxhowtos.org/C_C++/socket.htm
    Test with telnet:   https://netbeez.net/blog/telnet-to-test-connectivity-to-tcp/
    Test with CURL:     curl localhost:80/anyPathYouWant
*/

int main(int argc, char** argv)
{
    ///////////////////////////////////
    // Server
    tor::HttpServer server(8080);
    server.Use(
        tor::Middleware(
            [&](tor::HttpRequest request, tor::HttpResponse response)
            {
                return response;
            }
        ),
        "/home",
        "GET"
    );

    tor::HttpRouter router;
    router.Use(
        tor::Middleware(
            [&](tor::HttpRequest request, tor::HttpResponse response)
            {
                return response;
            }
        )
    );
    server.Use(router, "/users");

    return server.Listen();
    // Server
    ///////////////////////////////////
}