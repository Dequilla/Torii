#include <Http/HttpComponent.h>

namespace tor
{

    std::string HttpComponent::ToStdString() const
    {
        return this->ToString().GetSource();
    }

    std::ostream& operator<<(std::ostream& os, const tor::HttpComponent& obj)
    {
        return os << obj.ToStdString();
    }
    
}
