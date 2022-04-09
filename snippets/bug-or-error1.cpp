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

int f(int const* p, int a, int b)
{
    // Are we good?
    int r = 0;
    for (int i = a; i <= b; i++) {
        r += p[i];
    }
    return r;
}

int g(int const* p)
{
    // Is this OK?
    return f(p, -1, 1);
}
