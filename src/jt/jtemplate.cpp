// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include "jt/jtemplate.hpp"
#include "context.hpp"

namespace jt
{

jtemplate::jtemplate(std::shared_ptr<instruction> instruction)
: _instruction(instruction)
{

}

void jtemplate::render_to(nlohmann::json const & data, std::ostream & out) const
{
    context ctx = { data, data };
    _instruction->run(out, ctx);
}


}