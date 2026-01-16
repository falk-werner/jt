#include "jt/jt.hpp"
#include "jt/parser.hpp"
#include <fstream>
#include <sstream>

namespace jt
{

std::unique_ptr<template_i> from_file(std::string const & filename)
{
    std::ifstream template_file(filename);
    std::stringstream content;
    content << template_file.rdbuf();

    return from_string(content.str());
}

std::unique_ptr<template_i> from_string(std::string const & content)
{
    return parse(content);
}

std::string render(std::string const & templ, nlohmann::json const & data)
{
    std::stringstream out;
    render_to(templ, data, out);
    return out.str();
}

void render_to(std::string const & templ, nlohmann::json const & data, std::ostream & out)
{
    auto t = from_string(templ);
    return t->render_to(data, out);
}

}