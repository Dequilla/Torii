#pragma once
#include <string>

namespace tor 
{

    class String
    {
        std::string m_string;

    public:
        String();
        String(std::string string);

        std::string GetSource() const;
    };

}