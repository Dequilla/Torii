#include <Http/Parsing/Uri/Authority.h>

namespace tor 
{ 

    Authority::Authority(std::string host, std::uint16_t port, std::string userInfo) 
        : m_host(host), m_port(port), m_userInfo(userInfo)
    {

    }

    std::string Authority::ToString() const
    {
        std::string uri;

        // Check user info
        if(m_userInfo.size() > 0)
        {
            uri
                .append(m_userInfo)
                .append("@");
        }

        // Add host / domain
        uri
            .append(m_host);

        // Add port if available
        if(m_port != 0)
        {
            uri
                .append(":")
                .append(std::to_string(m_port));
        }

        return uri;
    }

}