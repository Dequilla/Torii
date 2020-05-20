#pragma once
#include <string>
#include <vector>

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

        std::vector<std::string> Split(char delimiter) const;
    };

}