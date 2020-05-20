#pragma once
#include <string>
#include <ostream>

namespace tor
{

    class HttpComponent
    {
    public:
        virtual std::string ToString() const = 0;
    };

    std::ostream& operator<<(std::ostream& os, const tor::HttpComponent& obj);
}
