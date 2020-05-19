#include <Http/Uri.h>

namespace tor
{
    Uri::Uri(tor::Authority authority, tor::Path path, tor::String scheme)
        : m_authority(authority), m_path(path), m_scheme(scheme)
    {

    }

    tor::String Uri::ToString() const
    {
        return tor::String(
            m_scheme.GetSource()
                .append(m_authority.ToString())
                .append(m_path.ToString())
        );
    }
}