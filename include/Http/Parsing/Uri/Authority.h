#pragma once
#include <cstdint>

#include <Http/Parsing/HttpComponent.h>

namespace tor { 

    class Authority : public HttpComponent
    {
        std::uint16_t   m_port;
        std::string     m_host,
                        m_userInfo;

    public: 
        Authority(std::string host, std::uint16_t port = 80, std::string userInfo = "");

        virtual std::string ToString() const;
    };

}