// Copyright 2022 John McFarlane
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "simulate.h"

#include "pid.h"

#include <csignal>
#include <cstdlib>

// from https://discourse.cmake.org/t/tests-that-are-meant-to-abort/537/4
// This is a hack to implement death tests in CTest.
extern "C" void error_test_handle_abort(int /*unused*/)
{
    std::exit(EXIT_FAILURE);  // NOLINT(concurrency-mt-unsafe)
}

auto main() -> int
{
    if (std::signal(SIGABRT, error_test_handle_abort) == SIG_ERR) {
        std::abort();
    }

    constexpr pid::parameters params{
            .k = {
                    .proportional = -0.1,
                    .integral = 0.5,
                    .derivative = 0.01},
            .dt = 0.1};
    constexpr pid::input in{
            .setpoint = 10.,
            .process_variable = 30.};
    constexpr auto max_iterations{100};

    pid::simulate(params, in, max_iterations);
}
