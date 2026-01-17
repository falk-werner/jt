// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_TEMPLATE_BUILDER_HPP
#define JT_TEMPLATE_BUILDER_HPP

#include "jt/template_i.hpp"
#include "jt/jtemplate.hpp"
#include "jt/path.hpp"
#include "jt/instructions.hpp"

#include <string>
#include <stack>
#include <memory>

namespace jt
{

/// @brief Builder to create a template.
class template_builder
{
public:
    /// @brief Creates a new builder instance.
    template_builder();

    /// @brief Adds a text instruction to the builder.
    /// @param text Text tp add.
    void add_text(std::string const & text);

    /// @brief Adds an instruction to resolve a variable to the builder.
    /// @param path Path to resolve.
    void add_get(path const & path);

    /// @brief Adds a loop instruction.
    /// 
    /// Following instructions are added as subinstructions of the loop
    /// until the loop is ended with end_loop().
    ///
    /// @param path Path of the group to loop.
    void begin_loop(path const & path);

    /// @brief  Ends a loop.
    /// @throws When there isn't a loop to end.
    void end_loop();

    /// @brief Creates a template from the added instructions.
    ///
    /// The builder is reset after this command.
    ///
    /// @return Template created from the previously added instructions.
    /// @throws On unfinished templates, e.g. unfinished loops.
    std::unique_ptr<template_i> build();
private:
    /// @brief Instructions added to the builder.
    std::stack<std::shared_ptr<instruction>> instructions;
};


}


#endif