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

#include <cstdlib>
#include <iostream>
#include <optional>
#include <span>
#include <string>

namespace acme {
    // everything needed for program to do its thing;
    // well-formed and error-free
    struct sanitized_input {
        // ...
    };

    // safety boundary; untrusted input; trusted output
    std::optional<sanitized_input> digest_input(std::span<char const* const> args);

    // free from error handling
    std::string do_the_thing(sanitized_input in);
}  // namespace acme

int main(int argc, char const* const* argv)
{
    // type safety is paramount; variable binding
    auto const args{std::span{argv, argv + argc}};

    auto const input{acme::digest_input(args)};
    if (!input) {
        return EXIT_FAILURE;
    }

    std::cout << acme::do_the_thing(*input);
    return EXIT_SUCCESS;
}
