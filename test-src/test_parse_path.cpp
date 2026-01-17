// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "jt/path.hpp"

TEST(parse_path, throw_on_empty_path)
{
    ASSERT_ANY_THROW({
        jt::parse_path("");
    });
}

TEST(parse_path, simple_path)
{
    auto path = jt::parse_path("simple");
    ASSERT_EQ(1, path.size());
    ASSERT_EQ(jt::path_element_type::path, path[0].type);
    ASSERT_EQ(std::string("simple"), path[0].value);
}

TEST(parse_path, root)
{
    auto path = jt::parse_path(".");
    ASSERT_EQ(1, path.size());
    ASSERT_EQ(jt::path_element_type::root, path[0].type);
}

TEST(parse_path, relative_path)
{
    auto path = jt::parse_path("some.relative.path");
    ASSERT_EQ(3, path.size());
    ASSERT_EQ(jt::path_element_type::path, path[0].type);
    ASSERT_EQ(std::string("some"), path[0].value);
    ASSERT_EQ(jt::path_element_type::path, path[1].type);
    ASSERT_EQ(std::string("relative"), path[1].value);
    ASSERT_EQ(jt::path_element_type::path, path[2].type);
    ASSERT_EQ(std::string("path"), path[2].value);
}

TEST(parse_path, absolute_path)
{
    auto path = jt::parse_path(".an.absolute.path");
    ASSERT_EQ(4, path.size());
    ASSERT_EQ(jt::path_element_type::root, path[0].type);
    ASSERT_EQ(jt::path_element_type::path, path[1].type);
    ASSERT_EQ(std::string("an"), path[1].value);
    ASSERT_EQ(jt::path_element_type::path, path[2].type);
    ASSERT_EQ(std::string("absolute"), path[2].value);
    ASSERT_EQ(jt::path_element_type::path, path[3].type);
    ASSERT_EQ(std::string("path"), path[3].value);
}