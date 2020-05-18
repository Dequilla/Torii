#include <Http/Uri.h>

namespace tor
{

    Uri::Uri(tor::String uri)
        : m_originalUri(uri)
    {
        // TODO: Implement parser for dynamic uris 
        //       like expreess /:id
    }

    tor::String Uri::ToString() const
    {
        return m_originalUri;
    }
}