#pragma once
#include <cstdint>
#include <Http/HttpComponent.h>
#include <Http/Uri/Authority.h>

namespace tor
{

    class Uri : public HttpComponent
    {
        Authority m_authority;

    public:
        // https://en.wikipedia.org/wiki/Uniform_Resource_Identifier
        Uri(tor::Authority authority, tor::String scheme = "http://");

        //static Uri FromString(tor::String uriString);

        virtual tor::String ToString() const;
    };

}