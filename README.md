# ACCU 2022 Demo

[![test](https://github.com/johnmcfarlane/pid/actions/workflows/test.yml/badge.svg)](https://github.com/johnmcfarlane/pid/actions/workflows/test.yml)

## Introduction

This project contains examples from my ACCU 2022 presentation,
[Contractual Disappointment in C++](johnmcfarlane.github.io/accu-2022/).

## Continuous Integration

The project's CI pipeline demonstrates how to maintain high-quality C++ by
running automated tests against tools such as:

* [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html),
* [CppCheck](http://cppcheck.net/) static analyser,
* [Clang](https://clang.llvm.org/) and [GCC](https://gcc.gnu.org/) compilers,
* [Clang Static Analyzer](https://clang-analyzer.llvm.org/),
* [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/) C++ linter and static
  analyser,
* [Conan](https://conan.io/) Python-based C++ package manager,
* [Include what you use](https://include-what-you-use.org/) tool to analyze `#include`s,
* [pre-commit](https://pre-commit.com/) linting framework with
  formatting and correctness checks for:
  * Bash
  * C++
  * CMake
  * JSON
  * Markdown
  * Python
  * YAML
* [UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html).
* [Valgrind](https://valgrind.org),
* [vcpkg](https://vcpkg.io/) CMake-based C++ package manager.

Developers are invited to suggest or add their favourite tools,
or to use this project as the starting point for their own C or C++ projects.

## Instructions

The project is built and tested on Linux and Windows.
It is designed to be easy to build and to run with:

* Conan package manager,
* CMake build system generator,
* A C++20-compatible compiler such as Clang, GCC or MSVC.

### Build and Test (Conan)

To build all tests and libraries using Conan on Linux,

1. create an empty build directory,

   ```sh
   mkdir -p build
   cd build/
   ```

1. install package dependencies,

   ```sh
   conan install --build=missing <path-to-project>
   ```

1. then configure, build, test, and install the programs:

   ```sh
   conan build <path-to-project>
   ```

### Build and Test (vcpkg)

To build all three utilities using vcpkg on Linux,

1. create an empty build directory,

   ```sh
   mkdir -p build
   cd build/
   ```

1. install vcpkg using [these instructions](https://vcpkg.io/en/getting-started.html),

   ```sh
   git clone https://github.com/Microsoft/vcpkg.git
   ./vcpkg/bootstrap-vcpkg.sh
   ```

1. then configure, build, and test the programs:

   ```sh
   cmake -DCMAKE_TOOLCHAIN_FILE=vcpkg/scripts/buildsystems/vcpkg.cmake <path-to-project>
   cmake --build .
   ctest
   ```
