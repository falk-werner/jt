// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_INSTRUCTION_HPP
#define JT_INSTRUCTION_HPP

#include "jt/context.hpp"
#include "jt/path.hpp"

#include <ostream>
#include <string>
#include <vector>

namespace jt
{

/// @brief Rendering instruction.
class instruction
{
public:
    virtual ~instruction() = default;

    /// @brief Runs the instruction on a given context.
    /// @param out Stream to render the results to.
    /// @param ctx Rendering context.
    virtual void run(std::ostream& out, context const & ctx) = 0;

    /// @brief Adds a subinstruction.
    ///
    /// This is used ny template bulder during template parsing.
    ///
    /// @note The default implementation does actually nothing.
    ///
    /// @param subinstruction Instruction to add.
    virtual void add_instruction(std::shared_ptr<instruction> subinstruction);
};

/// @brief Represents a block of (sub) instructions.
class block_instruction: public instruction
{
public:
    block_instruction();
    ~block_instruction() override = default;

    /// @brief Runs all subinstruction on the given context.
    /// @param out Stream to render the results to.
    /// @param ctx Rendering context.
    void run(std::ostream& out, context const & ctx) override;

    /// @brief Adds a (sub) instruction to the block.
    /// @param subinstruction Instruction to add
    void add_instruction(std::shared_ptr<instruction> subinstruction) override;
public:
    std::vector<std::shared_ptr<instruction>> instructions;
};

/// @brief Instruction to renders a text.
class text_instruction: public instruction
{
public:
    /// @brief Creates a new instance.
    /// @param text Text to print.
    text_instruction(std::string const & text);
    ~text_instruction() override = default;

    /// @brief Prints the text to the given stream.
    /// @param out Stream to print to.
    /// @param ctx Rendering context. Not used by this instruction.
    void run(std::ostream& out, context const & ctx) override;
private:
    /// @brief Text to print.
    std::string const _text;
};

/// @brief Resolves a variable and prints its value.
class get_instruction: public instruction
{
public:
    /// @brief Creates a new instance.
    /// @param p Path of the variable to render.
    get_instruction(path const & p);
    ~get_instruction() override = default;

    /// @brief Resolves the variable and prints its value.
    /// @param out Stream to print to.
    /// @param ctx Rendering context. Used to resolve the variable.
    void run(std::ostream& out, context const & ctx) override;
private:
    /// @brief Path of the variable to render.
    path const _p;
};

/// @brief Instruction to loop over a group of JSON data and run sub instructions.
class loop_instruction: public instruction
{
public:
    /// @brief Creates a new instance.
    /// @param path Path of a group of JSON data to loop. 
    loop_instruction(path const & path);
    ~loop_instruction() override = default;

    /// @brief Loops over a group of JSON data and runs sub instruction.
    /// @param out Stream to render sub instructions to.
    /// @param ctx Rendering context. Used to resolve group.
    void run(std::ostream& out, context const & ctx) override;

    /// @brief Adds a sub instruction
    ///
    /// Used by template builder during template parsing.
    ///
    /// @param subinstruction Sub instruction to add.
    void add_instruction(std::shared_ptr<instruction> subinstruction) override;
private:
    /// @brief Path to resolve the group to render.
    path const _path;

    /// @brief Instructions to run on each loop.
    std::vector<std::shared_ptr<instruction>> _instructions;
};

}

#endif
