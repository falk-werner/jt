#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include "jt/jt.hpp"

using json = nlohmann::json;

TEST(render, hello)
{
    std::string const templ = "Hello, {{whom}}!";
    auto data = json::parse(R"({"whom":"world"})");

    auto result = jt::render(templ, data);
    ASSERT_EQ("Hello, world!", result);
}

TEST(render, escape)
{
    std::string const templ = "{{ {{ }} variable }}";
    auto data = json::parse("{}");

    auto result = jt::render(templ, data);
    ASSERT_EQ("{{ variable }}", result);
}

TEST(render, loop)
{
    std::string const templ = "{{loop .}}{{ name }} {{end}}";
    auto data = json::parse(R"([{"name": "Apple"}, {"name": "Orange"}, {"name": "Banana"}])");

    auto result = jt::render(templ, data);
    ASSERT_EQ("Apple Orange Banana ", result);
}

TEST(render, absolute_path)
{
   std::string const templ = "{{loop favs}}{{ .name }} likes {{ name }}.\n{{end}}";
    auto data = json::parse(R"({
        "name": "Bob",
        "favs": [{"name": "music"}, {"name": "sports"}, {"name": "food"}]
    })");

    auto result = jt::render(templ, data);
    ASSERT_EQ("Bob likes music.\nBob likes sports.\nBob likes food.\n", result);   
}

TEST(render, fail_missing_end)
{
   std::string const templ = "{{loop favs}}{{ .name }} likes {{ name }}.\n";
    auto data = json::parse(R"({
        "name": "Bob",
        "favs": [{"name": "music"}, {"name": "sports"}, {"name": "food"}]
    })");

    ASSERT_ANY_THROW({
        jt::render(templ, data);
    });
}

TEST(render, fail_additional_end)
{
   std::string const templ = "{{loop favs}}{{ .name }} likes {{ name }}.\n{{end}}{{end}}";
    auto data = json::parse(R"({
        "name": "Bob",
        "favs": [{"name": "music"}, {"name": "sports"}, {"name": "food"}]
    })");

    ASSERT_ANY_THROW({
        jt::render(templ, data);
    });
}

TEST(render, fail_invalid_path)
{
   std::string const templ = "{{ invalid }}";
    auto data = json::parse(R"({})");

    ASSERT_ANY_THROW({
        jt::render(templ, data);
    });
}