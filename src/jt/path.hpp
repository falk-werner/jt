// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_PATH_HPP
#define JT_PATH_HPP

#include <string>
#include <vector>

namespace jt
{

/// @brief Type of a path element.
enum class path_element_type
{
    /// @brief Root element.
    root,

    /// @brief Path.
    path
};

/// @brief Element of a path.
struct path_element
{
    /// @brief Type of the path element.
    path_element_type type;

    /// @brief Value of the path element.
    std::string value;
};

using path = std::vector<path_element>;

/// @brief Parses a path from a string.
/// @param value String representation of the path.
/// @return Path.
/// @throws Invalid path, e.g. empty path.
path parse_path(std::string const & value);


}

#endif
