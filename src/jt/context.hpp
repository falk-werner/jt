// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_CONTEXT_HPP
#define JT_CONTEXT_HPP

#include "jt/path.hpp"
#include <nlohmann/json.hpp>

namespace jt
{

/// @brief Rendering context.
struct context
{
    /// @brief Root of the JSON data to render.
    nlohmann::json const & root;

    /// @brief Current context of the JSON data to render.
    nlohmann::json const & data;

    /// @brief Returns the JSON data referenced by the given path. 
    /// @param p Path to reference JSON data.
    /// @return Pointer to JSON data. Cannot be nullptr.
    /// @throws On invalid JSON reference.
    nlohmann::json const * get(path const & p) const;
};

}

#endif
