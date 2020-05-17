#include <Http/HttpVersion.h>

namespace tor 
{

    HttpVersion::HttpVersion(std::uint32_t major, std::uint32_t minor)
        : m_major(major), m_minor(minor)
    {

    }


    tor::String HttpVersion::ToString() const
    {
        return tor::String(
            std::to_string(m_major)
                .append(".")
                .append(std::to_string(m_minor))
        );
    }

}