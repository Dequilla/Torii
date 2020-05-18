#pragma once
#include <Http/HttpComponent.h>

namespace tor
{

    class HttpMethod : public HttpComponent
    {
    public:
        enum Method {
            UNKNOWN = -1,
            
            GET = 0,
            HEAD,
            POST,
            PUT,
            DELETE,
            CONNECT,
            OPTIONS,
            TRACE
        };

    protected:
        Method m_method;

    public:
        HttpMethod(Method method);

        virtual tor::String ToString() const;
    };

}