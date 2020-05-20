#include <Http/Parsing/Uri.h>

namespace tor
{
    Uri::Uri(tor::Authority authority, tor::Path path, std::string scheme)
        : m_authority(authority), m_path(path), m_scheme(scheme)
    {

    }

    std::string Uri::ToString() const
    {
        return std::string(m_scheme)
                    .append(m_authority.ToString())
                    .append(m_path.ToString());
    }
}