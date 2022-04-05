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

#include "pid_assert.h"

[[nodiscard]] auto pid::calculate(parameters params, state previous, input in)
        -> result
{
    PID_ASSERT(params.k.proportional >= 0);
    PID_ASSERT(params.k.integral >= 0);
    PID_ASSERT(params.k.derivative >= 0);
    PID_ASSERT(params.dt > 0);

    auto const error{in.setpoint - in.process_variable};
    auto const next_integral{previous.integral + error * params.dt};
    auto const derivative{(error - previous.error) / params.dt};

    components const terms{
            .proportional = params.k.proportional * error,
            .integral = params.k.integral * next_integral,
            .derivative = params.k.derivative * derivative};

    auto const output{terms.proportional + terms.integral + terms.derivative};
    PID_ASSERT(output == output);

    return result{
            output,
            state{next_integral, error}};
}
