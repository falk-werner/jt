#include "jt/path.hpp"

#include <sstream>
#include <stdexcept>

namespace jt
{

path parse_path(std::string const & value)
{
    jt::path path;

    if (value.empty()) {
        throw std::runtime_error("path is empty");
    }

    if (value[0] == '.') {
        path.push_back({jt::path_element_type::root, ""});
    }

    std::stringstream stream(value);
    std::string part;
    while (std::getline(stream, part, '.')) {
        if (!part.empty())  {
            path.push_back({jt::path_element_type::path, part});
        }
    }

    return path;
}


}