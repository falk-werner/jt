// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#ifndef JT_PARSER_HPP
#define JT_PARSER_HPP

#include "jt/template_i.hpp"
#include <memory>
#include <string>

namespace jt
{

std::unique_ptr<template_i> parse(std::string const & text);

}

#endif
