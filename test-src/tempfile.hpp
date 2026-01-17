#ifndef JTTEST_TEMPFILE_HPP
#define JTTEST_TEMPFILE_HPP

#include <string>

namespace jt::test
{

class tempfile
{
    tempfile(tempfile const &) = delete;
    tempfile& operator=(tempfile const &) = delete;
    tempfile(tempfile &&) = delete;
    tempfile& operator=(tempfile &&) = delete;
public:
    tempfile();
    ~tempfile();
    void write_all(std::string const & contents) const;
    std::string const & get_filename() const;
private:
    std::string filename;
};

}

#endif