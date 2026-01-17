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

/// @brief Create template from a given file.
/// @param filename Path of the template file.
/// @return Template.
/// @throws On template parsing errors.
std::unique_ptr<template_i> from_file(std::string const & filename);

/// @brief Create a template from a given string.
/// @param content Contents of the template.
/// @return Template.
/// @throws On template parsing errors.
std::unique_ptr<template_i> from_string(std::string const & content);

/// @brief Renders a template to a string.
/// @param templ Contents of the template.
/// @param data JSON data to render. 
/// @return Rendering result.
/// @throws On template parsing errors or rendering errors.
std::string render(std::string const & templ, nlohmann::json const & data);

/// @brief Renders a template to a stream.
/// @param templ Contents of teh template.
/// @param data JSON data to render.
/// @param out Stream to render to.
/// @throws On template parsing errors or rendering errors.
void render_to(std::string const & templ, nlohmann::json const & data, std::ostream & out);

}


#endif