#include <String.h>

namespace tor
{

    String::String()
        : m_string(std::string())
    {

    }

    String::String(std::string string)
        : m_string(string)
    {

    }

    std::string String::GetSource() const
    {
        return m_string;
    }

}