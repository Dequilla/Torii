#include <Http/Server/HttpRequest.h>

#include <Util/String.h>

#include <iostream>

namespace tor
{

    HttpRequest HttpRequest::FromString(std::string requestString)
    {
        tor::HttpRequest request;
        tor::String::Lines lines = tor::String::Split(requestString, '\n');

        tor::String::Lines firstLine = tor::String::Split(lines.at(0), ' ');
        request.m_method = firstLine.at(0);
        request.m_path = firstLine.at(1);
        request.m_httpVersion = HttpVersion(1, 1); // TODO GET FROM REQUEST STRING

        return request;
    }

}