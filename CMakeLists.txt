cmake_minimum_required(VERSION 3.28)
project(cpptemplate)

option(WITHOUT_TEST "Disable unit test" OFF)

set(CMAKE_CXX_STANDARD 17)

add_library(jt STATIC
    src/jt/jt.cpp
    src/jt/template_builder.cpp
    src/jt/context.cpp
    src/jt/jtemplate.cpp
    src/jt/parser.cpp
    src/jt/path.cpp
    src/jt/trim.cpp
    src/jt/instructions/instruction.cpp
    src/jt/instructions/block_instruction.cpp
    src/jt/instructions/text_instruction.cpp
    src/jt/instructions/get_instruction.cpp
    src/jt/instructions/loop_instruction.cpp
)
target_include_directories(jt PUBLIC inc)
target_include_directories(jt PRIVATE src)

add_executable(app src/app/main.cpp)
set_target_properties(app PROPERTIES OUTPUT_NAME jt)
target_link_libraries(app jt)

if(NOT(WITHOUT_TEST))

enable_testing()
include(CTest)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(alltests
    test-src/test_trim.cpp
    test-src/test_parse_path.cpp
    test-src/test_render.cpp
)

target_link_libraries(alltests PRIVATE jt GTest::gtest GTest::gtest_main)
target_include_directories(alltests PRIVATE src)
gtest_discover_tests(alltests)

endif()