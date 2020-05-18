#include <Http/HttpMethod.h>

namespace tor
{

    HttpMethod::HttpMethod(Method method)
        : m_method(method)
    {

    }

    tor::String HttpMethod::ToString() const
    {
        switch(m_method)
        {
            case Method::GET:
                return tor::String("GET");
            case Method::HEAD:
                return tor::String("HEAD");
            case Method::POST:
                return tor::String("POST");
            case Method::PUT:
                return tor::String("PUT");
            case Method::DELETE:
                return tor::String("DELETE");
            case Method::CONNECT:
                return tor::String("CONNECT");
            case Method::OPTIONS:
                return tor::String("OPTIONS");
            case Method::TRACE:
                return tor::String("TRACE");

            case Method::UNKNOWN:
            default:
                return tor::String("UNKNOWN");
        }
    }

}