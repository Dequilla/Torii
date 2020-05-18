#pragma once 
#include <Http/HttpMethod.h>
#include <Http/HttpVersion.h>

namespace tor 
{

    class HttpRequest 
    {
        HttpMethod m_method;
        HttpVersion m_version;

    public:
        HttpRequest(HttpMethod method = HttpMethod(), HttpVersion version = HttpVersion());

        static HttpRequest FromString(tor::String requestString);
    };

}