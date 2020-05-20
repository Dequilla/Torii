#pragma once
#include <string>

#include <Http/Server/HttpMiddleware.h>

namespace tor
{

    class HttpRouter : public tor::Middleware
    {
        HttpResponse callback(HttpRequest request, HttpResponse response);

    public:
        HttpRouter();
        ~HttpRouter();

        void Use(tor::Middleware middleware, std::string path = "", std::string method = "");

        void Get(tor::Middleware middleware, std::string path);
        void Post(tor::Middleware middleware, std::string path);
        void Put(tor::Middleware middleware, std::string path);
        void Delete(tor::Middleware middleware, std::string path);
    };

}