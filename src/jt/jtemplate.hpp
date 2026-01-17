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

/// @brief Template.
class jtemplate: public template_i
{
public:
    /// @brief Create a new template instance from an instruction.
    /// @param instruction Instruction of the template.
    jtemplate(std::shared_ptr<instruction> instruction);

    ~jtemplate() override = default;

    /// @brief Renders the template based on the provided data to stream.
    /// @param data JSON data used to render the template,
    /// @param out Stream to render the template.
    /// @throws On rendering errors.
    void render_to(nlohmann::json const & data, std::ostream & out) const;
private:
    std::shared_ptr<instruction> _instruction;
};

}

#endif
