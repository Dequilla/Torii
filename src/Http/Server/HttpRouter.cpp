#include <Http/Server/HttpRouter.h>

#include <iostream>

namespace tor
{

    HttpResponse HttpRouter::callback(HttpRequest request, HttpResponse response)
    {
        // Do all the routing here
        auto one = request.GetPath();
        auto two = request.GetMethod();
        auto three = request.GetVersion().ToString();
    }

    HttpRouter::HttpRouter()
        : Middleware(
            std::bind(
                &HttpRouter::callback,
                this,
                std::placeholders::_1,
                std::placeholders::_2
            )
        )
    {

    }

    HttpRouter::~HttpRouter()
    {

    }

    void HttpRouter::Use(tor::Middleware middleware, std::string path, std::string method)
    {

    }

    void HttpRouter::Get(tor::Middleware middleware, std::string path)
    {

    }

    void HttpRouter::Post(tor::Middleware middleware, std::string path)
    {

    }

    void HttpRouter::Put(tor::Middleware middleware, std::string path)
    {

    }

    void HttpRouter::Delete(tor::Middleware middleware, std::string path)
    {

    }
    
}