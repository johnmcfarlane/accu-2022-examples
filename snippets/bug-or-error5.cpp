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

int sample(int const* center, int first, int last)
{
    // First might be anything.
    int r = 0;
    for (int i = first; i <= last; i++) {
        r += center[i];
    }
    return r;
}

int g(int const* p)
{
    // center is not necessarily the start of the sequence.
    return sample(p, -1, 1);
}
