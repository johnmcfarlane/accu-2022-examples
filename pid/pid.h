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

#ifndef PID_PID_H
#define PID_PID_H

namespace pid {
    struct components {
        double proportional;
        double integral;
        double derivative;
    };

    // values kept constant throughout operation of a controller
    struct parameters {
        // non-negative factors used to generate PID terms
        components k;

        double dt;
    };

    struct state {
        double integral;
        double error;
    };

    struct input {
        // desired value
        double setpoint;

        // actual value
        double process_variable;
    };

    struct result {
        // corrective value to apply to system
        double correction;

        // to pass in to next iteration as input::previous state
        state current;
    };

    [[nodiscard]] auto calculate(parameters params, state previous, input in)
            -> result;
}  // namespace pid

#endif
