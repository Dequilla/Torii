#pragma once
#include <string>

namespace tor 
{

    class String
    {
        std::string m_string;

    public:
        String();
        String(const char* string);
        String(std::string string);

        operator std::string();

        std::string GetSource() const;
    };

}