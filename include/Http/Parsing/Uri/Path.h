#pragma once
#include <vector>

#include <Http/Parsing/HttpComponent.h>

namespace tor
{

    class Path : public HttpComponent
    {
    protected:
        std::string m_originalPath;
        std::vector<std::string> m_pathComponents;
        bool m_isExctracted = false;

        void Extract();

    public:
        Path(std::string path);

        bool Compare(Path otherPath);

        virtual std::string ToString() const;
    };  

}