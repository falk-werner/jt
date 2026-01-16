#ifndef JT_TEMPLATE_I_HPP
#define JT_TEMPLATE_I_HPP

#include <nlohmann/json.hpp>
#include <ostream>
#include <string>

namespace jt
{

class template_i
{
public:
    virtual ~template_i() = default;
    virtual void render_to(nlohmann::json const & data, std::ostream & out) const = 0;
};

}

#endif
