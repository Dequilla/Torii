#pragma once 
#include <Http/Parsing/HttpMethod.h>
#include <Http/Parsing/HttpVersion.h>

namespace tor 
{

    class HttpRequest 
    {
        HttpMethod m_method;
        HttpVersion m_version;

    public:
        HttpRequest(HttpMethod method = HttpMethod(), HttpVersion version = HttpVersion());

        static HttpRequest FromString(std::string requestString);
    };

}