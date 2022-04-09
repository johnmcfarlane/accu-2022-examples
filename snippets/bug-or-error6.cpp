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

#include <cassert>

int accumulate_neighborhood(int const* position, int offset_first, int offset_last)
{
    int r = 0;
    for (int i = offset_first; i <= offset_last; i ++)
    {
        r += position[i];
    }
    return r;
}

int sample(int const* center, int first, int last)
{
    return accumulate_neighborhood(center, first, last);
}

int accumulate_subrange(int const* numbers, int first, int last)
{
    assert(first >= 0);
    return accumulate_neighborhood(numbers, first, last);
}
