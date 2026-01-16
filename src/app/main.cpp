#include <jt/jt.hpp>

#include <getopt.h>

#include <iostream>
#include <fstream>
#include <sstream>

namespace
{

enum class command
{
    render,
    show_help
};

struct context
{
    context(int argc, char* argv[])
    : exit_code(EXIT_SUCCESS)
    , cmd(command::render)
    {
        option const opts[] =
        {
            {"template", required_argument, nullptr, 't'},
            {"data", required_argument, nullptr, 'd'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, 0, nullptr, 0}
        };

        opterr = 0;
        optind = 0;
        bool done = false;
        while (!done)
        {
            int option_index = 0;
            int const c = getopt_long(argc, argv, "t:d:h", opts, &option_index);
            switch (c)
            {
                case -1:
                    done = true;
                    break;
                case 'h':
                    cmd = command::show_help;
                    done = true;
                    break;
                case 't':
                    template_filename = optarg;
                    break;
                case 'd':
                    data_filename = optarg;
                    break;
                default:
                    std::cerr << "error: unknown argument" << std::endl;
                    exit_code = EXIT_FAILURE;
                    cmd = command::show_help;
                    done = true;
                    break;
            }
        }

        if ((cmd != command::render) || (exit_code == EXIT_FAILURE)) {
            return;
        }

        if (template_filename.empty()) {
            std::cerr << "error: missing required argument: -t" << std::endl;
            exit_code = EXIT_FAILURE;
            cmd = command::show_help;
            return;
        }

        if (data_filename.empty()) {
            std::cerr << "error: missing required argument: -d" << std::endl;
            exit_code = EXIT_FAILURE;
            cmd = command::show_help;
            return;
        }
    }

    int exit_code;
    command cmd;
    std::string template_filename;
    std::string data_filename;
};

void print_usage()
{
    std::cout << R"(jt, (c) 2026 Falk Werner
jt templating engine

Usage:
  jt -d DATA -t TEMPLATE

Arguments:
  -d, --data      path of json data file
  -t, --template  path of templat file
)";
}

std::string file_get_contents(std::string const & filename)
{
    std::stringstream contents;
    std::ifstream file(filename);
    contents << file.rdbuf();
    return contents.str();
}

int render(std::string const & template_filename, std::string const & data_filename)
{
    int exit_code = EXIT_SUCCESS;

    try {
        auto const templ = file_get_contents(template_filename);

        std::ifstream data_file(data_filename);
        auto const data = nlohmann::json::parse(data_file);

        jt::render_to(templ, data, std::cout);
    }
    catch (std::exception const & ex) {
        std::cerr << "error: " << ex.what() << std::endl;
        exit_code = EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "fatal: unexpected error" << std::endl;
        exit_code = EXIT_FAILURE;
    }

    return exit_code;
}

}

int main(int argc, char* argv[])
{
    context ctx(argc, argv);

    switch (ctx.cmd)
    {
        case command::render:
            ctx.exit_code = render(ctx.template_filename, ctx.data_filename);
            break;
        case command::show_help:
            // fall-through
        default:
            print_usage();
            break;
    }

    return ctx.exit_code;
}