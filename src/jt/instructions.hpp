#ifndef JT_INSTRUCTION_HPP
#define JT_INSTRUCTION_HPP

#include "jt/context.hpp"
#include "jt/path.hpp"

#include <ostream>
#include <string>
#include <vector>

namespace jt
{

class instruction
{
public:
    virtual ~instruction() = default;
    virtual void run(std::ostream& out, context const & ctx) = 0;
    virtual void add_instruction(std::shared_ptr<instruction> subinstruction);
};

class block_instruction: public instruction
{
public:
    block_instruction();
    ~block_instruction() override = default;
    void run(std::ostream& out, context const & ctx) override;
    void add_instruction(std::shared_ptr<instruction> subinstruction) override;
public:
    std::vector<std::shared_ptr<instruction>> instructions;
};

class text_instruction: public instruction
{
public:
    text_instruction(std::string const & text);
    ~text_instruction() override = default;
    void run(std::ostream& out, context const & ctx) override;
private:
    std::string const _text;
};

class get_instruction: public instruction
{
public:
    get_instruction(path const & p);
    ~get_instruction() override = default;
    void run(std::ostream& out, context const & ctx) override;
private:
    path const _p;
};

class loop_instruction: public instruction
{
public:
    loop_instruction(path const & path);
    ~loop_instruction() override = default;
    void run(std::ostream& out, context const & ctx) override;
    void add_instruction(std::shared_ptr<instruction> subinstruction) override;
private:
    path const _path;
    std::vector<std::shared_ptr<instruction>> _instructions;
};

}

#endif
