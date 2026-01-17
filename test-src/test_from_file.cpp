#include <gtest/gtest.h>
#include <jt/jt.hpp>
#include "tempfile.hpp"

using jt::test::tempfile;

TEST(from_file, load_template)
{
    tempfile temp;
    temp.write_all("Hello, {{ whom }}!");

    jt::from_file(temp.get_filename());
}

TEST(from_file, fail_invalid_file)
{
    std::string filename;
    {
        tempfile temp;
        temp.write_all("Hello, {{ whom }}!");
        filename = temp.get_filename();
    }

    ASSERT_ANY_THROW({
        jt::from_file(filename + "invalid");
    });
}
