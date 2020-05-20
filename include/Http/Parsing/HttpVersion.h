#pragma once
#include <cstdint>

#include <Http/Parsing/HttpComponent.h>

namespace tor
{

    class HttpVersion : public HttpComponent
    {
        std::uint32_t m_major, m_minor;

    public:
        HttpVersion(std::uint32_t major = 1, std::uint32_t minor = 1);

        std::uint32_t GetMajor() const;
        std::uint32_t GetMinor() const;

        virtual std::string ToString() const;
    };

}