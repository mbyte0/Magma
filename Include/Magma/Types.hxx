#pragma once

static_assert(8 * sizeof(float)  == 32);
static_assert(8 * sizeof(double) == 64);

#include <inttypes.h>
#include <string>
#include <string_view>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <functional>

// #include <glm/glm.hpp>

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

// namespace Math = glm;
