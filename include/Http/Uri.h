#pragma once
#include <Http/HttpComponent.h>

namespace tor
{

    class Uri : public HttpComponent
    {
        tor::String m_originalUri;

    public:
        Uri(tor::String uri);

        virtual tor::String ToString() const;
    };

}