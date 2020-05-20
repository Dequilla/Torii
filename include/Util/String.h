#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace tor { namespace String {

    using Lines = std::vector<std::string>;

    inline Lines Split(std::string source, char delimiter = '\n')
    {
        std::vector<std::string> lines;
        std::istringstream ss(source);
        for(std::string line; std::getline(ss, line, delimiter);)
        {
            lines.push_back(line);
        }
        return lines;
    }

}}