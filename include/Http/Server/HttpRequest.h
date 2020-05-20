#pragma once
#include <string>
#include <Http/Parsing/HttpVersion.h>

namespace tor
{
    
    class HttpRequest
    {
        std::string m_method;
        std::string m_host;
        std::string m_path;
        tor::HttpVersion m_httpVersion;
        
        // Parameters that we need in a request
        /*
            GET /login HTTP/1.1
            Host: www.example.com

            or

            POST /login HTTP/1.1
            Host: www.example.com
            Content-Type: application/json
            Content-Length: [length]

            {
                "username": "admin",
                "password": "admin"
            }
        */

    public:
        static HttpRequest FromString(std::string request);
    };

}