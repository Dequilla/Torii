#pragma once
#include <cstdint>

#include <String.h>
#include <Http/HttpComponent.h>

namespace tor { 

    class Authority : public HttpComponent
    {
        std::uint16_t   m_port;
        tor::String     m_host,
                        m_userInfo;

    public: 
        Authority(tor::String host, std::uint16_t port = 80, tor::String userInfo = "");

        virtual tor::String ToString() const;
    };

}