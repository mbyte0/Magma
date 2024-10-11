// Copyrigh 2024 - Present, MByte0
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

#include "Magma/Core/Logger.hxx"

// #include <iostream>
#include "fmt/base.h"
#include "fmt/chrono.h"
// #include <thread>
// #include "fmt/std.h"

namespace Magma {

  Logger::Logger(StringView name)
  : m_Name(name) {

  }

  void Logger::Log(LogType type, CString file, const std::source_location& location, StringView message) {
    auto now = std::chrono::system_clock::now();
    fmt::print(LogTypeToFmtTextStyle(type), "[{}] [{}] [{}] {}:{} ({}):", now, m_Name, LogTypeToString(type), file, location.line(), location.function_name());
    fmt::print(" {}\n", message);
  }

  String Logger::LogTypeToString(LogType type) {
    switch (type) {
      case LogType::Trace:   return "Trace";
      case LogType::Debug:   return "Debug";
      case LogType::Info:    return "Info";
      case LogType::Warning: return "Warning";
      case LogType::Error:   return "Error";
      case LogType::Fatal:   return "Fatal";
    }
  }

  fmt::text_style Logger::LogTypeToFmtTextStyle(LogType type) {
    switch (type) {
      case LogType::Trace:   return fmt::fg(fmt::color::dark_gray);
      case LogType::Debug:   return fmt::fg(fmt::color::blue);
      case LogType::Info:    return fmt::fg(fmt::color::green);
      case LogType::Warning: return fmt::emphasis::bold | fmt::fg(fmt::color::yellow);
      case LogType::Error:   return fmt::emphasis::bold | fmt::fg(fmt::color::red);
      case LogType::Fatal:   return fmt::emphasis::bold | fmt::bg(fmt::color::red) | fmt::fg(fmt::color::white);
    }
  }

} // namespace Magma
