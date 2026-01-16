#include "jt/instructions.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;


namespace jt
{

get_instruction::get_instruction(path const & p)
: _p(p)
{

}

void get_instruction::run(std::ostream& out, context const & ctx)
{
    auto const * value = ctx.get(_p);
    out << value->get<std::string>();
}

}