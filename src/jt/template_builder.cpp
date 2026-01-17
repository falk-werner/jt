// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include "jt/template_builder.hpp"

namespace jt
{

template_builder::template_builder()
{
    std::shared_ptr<instruction> top = std::make_shared<block_instruction>();
    instructions.push(top);
}


void template_builder::add_text(std::string const & text)
{
    instructions.top()->add_instruction(std::make_shared<text_instruction>(text));
}

void template_builder::add_get(path const & path)
{
    instructions.top()->add_instruction(std::make_shared<get_instruction>(path));
}

void template_builder::begin_loop(path const & path)
{
    auto loop = std::make_shared<loop_instruction>(path);
    instructions.top()->add_instruction(loop);
    instructions.push(loop);
}

void template_builder::end_loop()
{
    instructions.pop();
    if (instructions.empty()) {
        throw std::runtime_error("no loop for end");
    }
}


std::unique_ptr<template_i> template_builder::build()
{
    if (instructions.size() != 1) {
        throw std::runtime_error("missind end");
    }

    auto templ =  std::make_unique<jtemplate>(instructions.top());
    return templ;
}



}