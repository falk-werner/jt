// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include "jt/instructions.hpp"

namespace jt
{

text_instruction::text_instruction(std::string const & text)
: _text(text)
{

}

void text_instruction::run(std::ostream& out, context const & ctx)
{
    out << _text;
}

}