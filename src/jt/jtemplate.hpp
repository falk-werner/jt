// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_CPP_TEMPLATE_HPP
#define JT_CPP_TEMPLATE_HPP

#include "jt/instructions.hpp"
#include "jt/template_i.hpp"

#include <nlohmann/json.hpp>

#include <ostream>
#include <memory>

namespace jt
{

class jtemplate: public template_i
{
public:
    jtemplate(std::shared_ptr<instruction> instruction);
    ~jtemplate() override = default;
    void render_to(nlohmann::json const & context, std::ostream & out) const;
private:
    std::shared_ptr<instruction> _instruction;
};

}

#endif
