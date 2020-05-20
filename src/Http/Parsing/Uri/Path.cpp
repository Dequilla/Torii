#include <Http/Parsing/Uri/Path.h>

#include <String.h>

namespace tor
{

    Path::Path(std::string path)
        : m_originalPath(path)
    {   

    }

    void Path::Extract()
    {
        m_pathComponents = tor::String(m_originalPath).Split('/');

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
            std::string local = m_pathComponents.at(index); 
            std::string other = otherPath.m_pathComponents.at(index);

            // They are the exact same (not same instance)
            if(local == other) continue;

            // One is a placeholder (always match)
            // TODO: Make placeholders optional
            if(local.at(0) == ':' || other.at(0) == ':') continue;

            return false;
        }

        return true;
    }

    std::string Path::ToString() const
    {
        return m_originalPath;
    }

}