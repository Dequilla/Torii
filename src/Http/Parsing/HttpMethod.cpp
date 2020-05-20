#include <Http/Parsing/HttpMethod.h>

namespace tor
{

    HttpMethod::HttpMethod(Method method)
        : m_method(method)
    {

    }

    std::string HttpMethod::ToString() const
    {
        switch(m_method)
        {
            case Method::GET:
                return "GET";
            case Method::HEAD:
                return "HEAD";
            case Method::POST:
                return "POST";
            case Method::PUT:
                return "PUT";
            case Method::DELETE:
                return "DELETE";
            case Method::CONNECT:
                return "CONNECT";
            case Method::OPTIONS:
                return "OPTIONS";
            case Method::TRACE:
                return "TRACE";

            case Method::UNKNOWN:
            default:
                return "UNKNOWN";
        }
    }

}