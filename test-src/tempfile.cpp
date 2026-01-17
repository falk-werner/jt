#include "tempfile.hpp"

#include <unistd.h>

#include <cstdlib>
#include <fstream>
#include <stdexcept>

namespace jt::test
{

tempfile::tempfile()
{
    char buffer[] = "/tmp/jt_test_XXXXXXXX";
    int fd = mkstemp(buffer);
    if (fd <= 0) {
        std::runtime_error("failed to create temporary file");
    }
    close(fd);

    filename = buffer;
}

tempfile::~tempfile()
{
    unlink(filename.c_str());
}

void tempfile::write_all(std::string const & contents) const
{
    std::ofstream file(filename);
    file << contents;
}

std::string const & tempfile::get_filename() const
{
    return filename;
}

}