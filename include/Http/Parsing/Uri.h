#pragma once
#include <cstdint>
#include <Http/Parsing/HttpComponent.h>
#include <Http/Parsing/Uri/Authority.h>
#include <Http/Parsing/Uri/Path.h>

namespace tor
{

    class Uri : public HttpComponent
    {
        tor::Authority m_authority;
        std::string m_scheme; 
        tor::Path m_path;

    public:
        // https://en.wikipedia.org/wiki/Uniform_Resource_Identifier
        Uri(tor::Authority authority, tor::Path path, std::string scheme = "http://");

        //static Uri FromString(tor::String uriString);

        virtual std::string ToString() const;
    };

}