// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include "jt/instructions.hpp"

namespace jt
{

loop_instruction::loop_instruction(path const & path)
: _path(path)
{

}

void loop_instruction::run(std::ostream& out, context const & ctx)
{
    auto const * arr = ctx.get(_path);
    for(auto const & item: *arr) {
        context sub_context = { ctx.root, item};
        for(auto const & instr: _instructions) {
            instr->run(out, sub_context);
        }
    }
}

void loop_instruction::add_instruction(std::shared_ptr<instruction> subinstruction)
{
    _instructions.push_back(subinstruction);
}

}