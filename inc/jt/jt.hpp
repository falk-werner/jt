// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_HPP
#define JT_HPP

#include <jt/template_i.hpp>

#include <nlohmann/json.hpp>

#include <memory>
#include <string>
#include <ostream>

namespace jt
{

std::unique_ptr<template_i> from_file(std::string const & filename);

std::unique_ptr<template_i> from_string(std::string const & content);

std::string render(std::string const & templ, nlohmann::json const & data);

void render_to(std::string const & templ, nlohmann::json const & data, std::ostream & out);

}


#endif