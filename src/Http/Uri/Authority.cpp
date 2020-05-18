#include <Http/Uri/Authority.h>

namespace tor 
{ 

    Authority::Authority(tor::String host, std::uint16_t port, tor::String userInfo) 
        : m_host(host), m_port(port), m_userInfo(userInfo)
    {

    }

    tor::String Authority::ToString() const
    {
        tor::String uri;

        // Check user info
        if(m_userInfo.GetSource().size() >= 0)
        {
            uri.GetSource()
                .append(m_userInfo.GetSource())
                .append("@");
        }

        // Add host / domain
        uri.GetSource()
            .append(m_host.GetSource());

        // Add port if available
        if(m_port != 0)
        {
            uri.GetSource()
                .append(":")
                .append(std::to_string(m_port));
        }

        return uri;
    }

}