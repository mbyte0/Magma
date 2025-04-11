// Copyrigh 2025 - Present, MByte0
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

#pragma once

static_assert(8 * sizeof(float)  == 32);
static_assert(8 * sizeof(double) == 64);

#include <inttypes.h>
#include <string>
#include <string_view>
#include <map>              // IWYU pragma: keep
#include <unordered_map>    // IWYU pragma: keep
#include <vector>           // IWYU pragma: keep
#include <array>
#include <functional>
#include <memory>           // IWYU pragma: keep

#include <glm/glm.hpp>

using Int8    = int8_t;
using Int16   = int16_t;
using Int32   = int32_t;
using Int64   = int64_t;

using UInt8   = uint8_t;
using UInt16  = uint16_t;
using UInt32  = uint32_t;
using UInt64  = uint64_t;

using Float32 = float;
using Float64 = double;

using Size    = size_t;
using Bool    = bool;

using Char        = char;
using UChar       = unsigned char;
using CString     = const char*;
using String      = std::string;
using StringView  = std::string_view;

template <typename Key, typename Value>
using Map = std::map<Key, Value>;

template <typename Key, typename Value>
using UnorderedMap = std::unordered_map<Key, Value>;

template <typename Type>
using Vector = std::vector<Type>;

template <typename Type, UInt32 Size>
using Array = std::array<Type, Size>;

template <typename T>
using Function = std::function<T>;

namespace Math = glm;

#if MAGMA_PLATFORM_WINDOWS && MAGMA_BUILD
    #define MAGMA_API __declspec(dllexport)
#elif MAGMA_PLATFORM_WINDOWS && !MAGMA_BUILD
    #define MAGMA_API __declspec(dllimport)
#else
    #define MAGMA_API
#endif
