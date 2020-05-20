#pragma once
#include <HttpMiddlerware.h>

namespace tor
{

    class HttpRouter : public tor::Middleware
    {
    public:
        HttpRouter();
        ~HttpRouter();

        void Use(tor::Middleware middleware, tor::String path = "", tor::String method = "");

        void Get(tor::Middleware middleware, tor::String path);
        void Post(tor::Middleware middleware, tor::String path);
        void Put(tor::Middleware middleware, tor::String path);
        void Delete(tor::Middleware middleware, tor::String path);
    };

}