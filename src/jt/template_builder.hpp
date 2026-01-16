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

class template_builder
{
public:
    template_builder();
    void add_text(std::string const & text);
    void add_get(path const & path);
    void begin_loop(path const & path);
    void end_loop();
    std::unique_ptr<template_i> build();
private:
    std::stack<std::shared_ptr<instruction>> instructions;
};


}


#endif