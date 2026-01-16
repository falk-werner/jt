#include "jt/context.hpp"

namespace jt
{

nlohmann::json const * context::get(path const & p) const
{
    nlohmann::json const * current = &data;

    for(auto const & element: p) {
        switch(element.type)
        {
            case path_element_type::root:
                current = &root;
                break;
            case path_element_type::path:
                current = &(current->at(element.value));
                break;
        }
    }

    return current;
}

}