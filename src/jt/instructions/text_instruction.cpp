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