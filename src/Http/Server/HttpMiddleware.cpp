#include <Http/Server/HttpMiddleware.h>

namespace tor
{

    Middleware::Middleware(Callback callback)
        : m_callback(callback)
    {

    }

    Middleware::~Middleware()
    {

    }
    

    HttpResponse Middleware::Run(HttpRequest request, HttpResponse response)
    {
        return m_callback(request, response);
    }
    
}