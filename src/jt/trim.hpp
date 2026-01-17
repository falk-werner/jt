// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_TRIM_HPP
#define JT_TRIM_HPP

#include <string>

namespace jt
{

/// @brief Removes whitespace at the beginning and at the end of string.
/// @note The string is trimmed inplace.
/// @param value String to trim.
void trim(std::string & value);

}


#endif
