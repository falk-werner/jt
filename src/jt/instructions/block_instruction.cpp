// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include "jt/instructions.hpp"

namespace jt
{

block_instruction::block_instruction()
{

}

void block_instruction::run(std::ostream& out, context const & ctx)
{
    for (auto const & instr: instructions) {
        instr->run(out, ctx);
    }
}

void block_instruction::add_instruction(std::shared_ptr<instruction> subinstruction)
{
    instructions.push_back(subinstruction);
}


}