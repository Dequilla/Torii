#include <Exception.h>

namespace tor {

    BaseException::BaseException(const std::string& msg) 
        : m_msg(msg)
    {
    }

    const char* BaseException::what() const throw()
    {
        return m_msg.c_str();
    }
    
}