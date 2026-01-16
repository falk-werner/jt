#include "jt/parser.hpp"
#include "jt/template_builder.hpp"
#include "jt/trim.hpp"
#include "jt/path.hpp"

#include <iostream>
#include <stdexcept>

namespace jt
{

std::unique_ptr<template_i> parse(std::string const & text)
{
    template_builder builder;

    size_t offset = 0;
    auto pos = text.find("{{", offset);
    while (pos != std::string::npos)
    {
        if (offset < pos) {
            auto const value = text.substr(offset, pos - offset);
            builder.add_text(value);
        }
        offset = pos + 2;
        auto end = text.find("}}", offset);
        if (end == std::string::npos)
        {
            throw std::runtime_error("unterminated template");
        }

        std::string instruction = text.substr(offset, end - offset);        
        trim(instruction);

        if (instruction == "{{") {
            builder.add_text("{{");
        }
        else if (0 == instruction.find("#")) {
            // skip comments
        }
        else if (0 == instruction.find("loop ")) {
            std::string value = instruction.substr(4);
            trim(value);
            auto path = parse_path(value);
            builder.begin_loop(path);
        }
        else if (instruction == "end") {
            builder.end_loop();
        }
        else {
            auto path = parse_path(instruction);
            builder.add_get(path);
        }
        
        offset = end + 2;
        pos = text.find("{{", offset);
    }

    auto const value = text.substr(offset);
    builder.add_text(value);

    return builder.build();
}

}