#pragma once
#include <String.h>
#include <Http/Server/HttpResponse.h>
#include <Http/Server/HttpRequest.h>

#include <functional>
#include <vector>

namespace tor
{

    using Callback = std::function<HttpResponse(HttpRequest, HttpResponse)>;

    class Middleware
    {
        Callback m_callback;

    public:
        Middleware(Callback callback);
        ~Middleware();

        HttpResponse Run(HttpRequest request, HttpResponse response);
    };

}