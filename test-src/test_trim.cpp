// SPDX-FileCopyrightText: 2026 Falk Werner <github.com/falk-werner>
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "jt/trim.hpp"

TEST(trim, ltrim)
{
    std::string value = " \r\n\t\ffoo";
    jt::trim(value);
    ASSERT_EQ(value, "foo");
}

TEST(trim, rtrim)
{
    std::string value = "foo \r\n\t\f";
    jt::trim(value);
    ASSERT_EQ(value, "foo");
}

TEST(trim, trim)
{
    std::string value = "\f\t\n\r foo \r\n\t\f";
    jt::trim(value);
    ASSERT_EQ(value, "foo");
}

TEST(trim, notrim)
{
    std::string value = "foo";
    jt::trim(value);
    ASSERT_EQ(value, "foo");
}

TEST(trim, empty)
{
    std::string value;
    jt::trim(value);
    ASSERT_EQ(value, "");
}
