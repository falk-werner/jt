#ifndef JT_PATH_HPP
#define JT_PATH_HPP

#include <string>
#include <vector>

namespace jt
{

enum class path_element_type
{
    root,
    path
};

struct path_element
{
    path_element_type type;
    std::string value;
};

using path = std::vector<path_element>;

path parse_path(std::string const & value);


}

#endif
