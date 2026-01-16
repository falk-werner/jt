#include "jt/trim.hpp"

namespace jt
{

void trim(std::string & value)
{
    char const whitespace[] = " \n\r\t\f";
    value.erase(0, value.find_first_not_of(whitespace));
    value.erase(value.find_last_not_of(whitespace) + 1);
}

}