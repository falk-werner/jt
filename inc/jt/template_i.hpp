// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_TEMPLATE_I_HPP
#define JT_TEMPLATE_I_HPP

#include <nlohmann/json.hpp>
#include <ostream>
#include <string>

namespace jt
{

/// @brief Template interface.
class template_i
{
public:
    virtual ~template_i() = default;

    /// @brief Renders the template to a stream.
    /// @param data JSON data to render.
    /// @param out Stream to render to.
    /// @throws On rendering error, e.g. invalid access to JSON data.
    virtual void render_to(nlohmann::json const & data, std::ostream & out) const = 0;
};

}

#endif
