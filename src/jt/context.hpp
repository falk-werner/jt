// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_CONTEXT_HPP
#define JT_CONTEXT_HPP

#include "jt/path.hpp"
#include <nlohmann/json.hpp>

namespace jt
{

struct context
{
    nlohmann::json const & root;
    nlohmann::json const & data;

    nlohmann::json const * get(path const & p) const;
};

}

#endif
