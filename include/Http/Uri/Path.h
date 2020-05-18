#pragma once
#include <vector>

#include <Http/HttpComponent.h>
#include <String.h>

namespace tor
{

    class Path : public HttpComponent
    {
    protected:
        tor::String m_originalPath;
        std::vector<tor::String> m_pathComponents;
        bool m_isExctracted = false;

        void Extract();

    public:
        Path(tor::String path);

        bool Compare(Path otherPath);

        virtual tor::String ToString() const;
    };  

}