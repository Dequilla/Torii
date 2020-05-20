#include <Http/Parsing/HttpRequest.h>

namespace tor
{
    
    HttpRequest::HttpRequest(HttpMethod method, HttpVersion version)
        : m_method(method), m_version(version)
    {
        
    }

    static HttpRequest FromString(std::string requestString)
    {
        // TODO: Implement parser
        return HttpRequest();
    }

}