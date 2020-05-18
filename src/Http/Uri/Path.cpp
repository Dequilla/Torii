#include <Http/Uri/Path.h>

namespace tor
{

    Path::Path(tor::String path)
        : m_originalPath(path)
    {   

    }

    void Path::Extract()
    {
        m_pathComponents = m_originalPath.Split('/');

        m_isExctracted = true;
    }

    bool Path::Compare(Path otherPath)
    {
        if(!m_isExctracted) this->Extract();
        if(!otherPath.m_isExctracted) otherPath.Extract();

        // If not same length obviously not the same
        if(m_pathComponents.size() != otherPath.m_pathComponents.size()) return false;

        // Ensure they are the same
        for(std::uint32_t index = 0; index < m_pathComponents.size(); index++)
        {
            // TODO: Check size of string (should 0 be allowed?)
            tor::String local = m_pathComponents.at(index); 
            tor::String other = otherPath.m_pathComponents.at(index);

            // They are the exact same (not same instance)
            if(local.GetSource() == other.GetSource()) continue;

            // One is a placeholder (always match)
            // TODO: Make placeholders optional
            if(local.GetSource().at(0) == ':' || other.GetSource().at(0) == ':') continue;

            return false;
        }

        return true;
    }

    tor::String Path::ToString() const
    {
        return m_originalPath;
    }

}