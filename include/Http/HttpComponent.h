#pragma once
#include <String.h>
#include <ostream>

namespace tor
{

    class HttpComponent
    {
    public:
        virtual tor::String ToString() const = 0;

        virtual std::string ToStdString() const;
    };

    std::ostream& operator<<(std::ostream& os, const tor::HttpComponent& obj);
}
