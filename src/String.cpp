#include <String.h>

#include <sstream>

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

    std::vector<std::string> String::Split(char delimiter) const
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(m_string);

        while (std::getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        
        return tokens;
    }

}