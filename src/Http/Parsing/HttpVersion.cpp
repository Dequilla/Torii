#include <Http/Parsing/HttpVersion.h>

namespace tor 
{

    HttpVersion::HttpVersion(std::uint32_t major, std::uint32_t minor)
        : m_major(major), m_minor(minor)
    {

    }

    std::uint32_t HttpVersion::GetMajor() const
    {
        return m_major;
    }

    std::uint32_t HttpVersion::GetMinor() const
    {
        return m_minor;
    }

    std::string HttpVersion::ToString() const
    {
        return std::to_string(m_major)
                    .append(".")
                    .append(std::to_string(m_minor));
    }

}