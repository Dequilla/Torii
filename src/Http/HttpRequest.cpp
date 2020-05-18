#include <Http/HttpRequest.h>

namespace tor
{
    
    HttpRequest::HttpRequest(HttpMethod method, HttpVersion version)
        : m_method(method), m_version(version)
    {
        
    }

    static HttpRequest FromString(tor::String requestString)
    {
        // TODO: Implement parser
        return HttpRequest();
    }

}