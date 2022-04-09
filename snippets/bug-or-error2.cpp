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

int accumulate(int const* numbers, int first, int last)
{
    // Are we good?
    int r = 0;
    for (int i = first; i <= last; i ++)
    {
        r += numbers[i];
    }
    return r;
}

int g(int const* p)
{
    // Is this OK?
    return accumulate(p, -1, 1);
}
