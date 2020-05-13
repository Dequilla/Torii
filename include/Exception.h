#pragma once

#include <exception>
#include <string>

namespace tor 
{

    class BaseException : public std::exception
    {
        std::string m_msg;

    public:
        BaseException(const std::string& msg);

        virtual const char* what() const throw();
    };

}