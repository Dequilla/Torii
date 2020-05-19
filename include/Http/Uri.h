#pragma once
#include <cstdint>
#include <Http/HttpComponent.h>
#include <Http/Uri/Authority.h>
#include <Http/Uri/Path.h>

namespace tor
{

    class Uri : public HttpComponent
    {
        tor::Authority m_authority;
        tor::String m_scheme; 
        tor::Path m_path;

    public:
        // https://en.wikipedia.org/wiki/Uniform_Resource_Identifier
        Uri(tor::Authority authority, tor::Path path, tor::String scheme = "http://");

        //static Uri FromString(tor::String uriString);

        virtual tor::String ToString() const;
    };

}