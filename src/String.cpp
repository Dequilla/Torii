#include <String.h>

namespace tor
{

    String::String()
        : m_string(std::string())
    {

    }

    String::String(const char* string)
        : m_string(string)
    {
        
    }

    String::String(std::string string)
        : m_string(string)
    {

    }

    String::operator std::string()
    {
        return m_string;
    }

    std::string String::GetSource() const
    {
        return m_string;
    }

}