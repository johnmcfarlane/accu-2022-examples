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

#include "pid.h"

#include <catch2/catch.hpp>

namespace pid {
    // NOLINTNEXTLINE(modernize-use-trailing-return-type)
    [[nodiscard]] auto operator==(pid::state const& lhs, pid::state const& rhs)
    {
        return lhs.integral == rhs.integral && lhs.error == rhs.error;
    }

    // NOLINTNEXTLINE(modernize-use-trailing-return-type)
    [[nodiscard]] auto operator==(pid::result const& lhs, pid::result const& rhs)
    {
        return lhs.correction == rhs.correction
            && lhs.current == rhs.current;
    }
}  // namespace pid

SCENARIO("pid::calculate will simulate a PID controller")
{
    GIVEN("a zeroed set of PID factors and a time delta")
    {
        pid::parameters const params{
                .k = pid::components{0, 0, 0},
                .dt = 1};

        WHEN("initial state is entered")
        {
            pid::input const input{
                    .setpoint = 0,
                    .process_variable = 0};
            pid::state const previous{
                    .integral = 0,
                    .error = 0};

            auto const result{pid::calculate(params, previous, input)};

            THEN("very little happens")
            {
                REQUIRE(result == pid::result{});
            }
        }
    }
}
// LCOV_EXCL_END
