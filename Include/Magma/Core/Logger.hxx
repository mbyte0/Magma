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


#pragma once

#include <source_location>
#include "Magma/Types.hxx"
#include "fmt/format.h"
#include "fmt/color.h"

namespace Magma {

  class Logger
  {
  public:
    enum class LogType : UInt8 {
      Trace = 0,
      Debug,
      Info,
      Warning,
      Error,
      Fatal
    };

  public:
    Logger(StringView name);

    void Log(LogType type, CString file, const std::source_location& location, StringView message);

    template<typename... Args>
    inline void Log(LogType type, CString file, const std::source_location& location, fmt::format_string<Args...> formatString, Args&&... args) {
      Log(type, file, location, fmt::format(formatString, std::forward<Args>(args)...));
    }

    inline void SetName(StringView name) {
      m_Name = name;
    }

  private:
    String LogTypeToString(LogType type);
    fmt::text_style LogTypeToFmtTextStyle(LogType type);

  private:
    std::string m_Name;

  };

#if MAGMA_BUILD
  inline Logger magmaLogger("Magma");
#else
  inline Logger clientLogger("Application");
#endif //MAGMA_BUILD

} // namespace Magma

#define MAGMA_LOG_TRACE_CUSTOM(loggerInstance, ...)   loggerInstance.Log(Magma::Logger::LogType::Trace,   __FILE__, std::source_location::current(), __VA_ARGS__)
#define MAGMA_LOG_DEBUG_CUSTOM(loggerInstance, ...)   loggerInstance.Log(Magma::Logger::LogType::Debug,   __FILE__, std::source_location::current(), __VA_ARGS__)
#define MAGMA_LOG_INFO_CUSTOM(loggerInstance, ...)    loggerInstance.Log(Magma::Logger::LogType::Info,    __FILE__, std::source_location::current(), __VA_ARGS__)
#define MAGMA_LOG_WARNING_CUSTOM(loggerInstance, ...) loggerInstance.Log(Magma::Logger::LogType::Warning, __FILE__, std::source_location::current(), __VA_ARGS__)
#define MAGMA_LOG_ERROR_CUSTOM(loggerInstance, ...)   loggerInstance.Log(Magma::Logger::LogType::Error,   __FILE__, std::source_location::current(), __VA_ARGS__)
#define MAGMA_LOG_FATAL_CUSTOM(loggerInstance, ...)   loggerInstance.Log(Magma::Logger::LogType::Fatal,   __FILE__, std::source_location::current(), __VA_ARGS__)


// Check if this header is included in Magma code or in a Magma Application
#if MAGMA_BUILD

  #define MG_LOG_TRACE(...)    MAGMA_LOG_TRACE_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)
  #define MG_LOG_DEBUG(...)    MAGMA_LOG_DEBUG_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)
  #define MG_LOG_INFO(...)     MAGMA_LOG_INFO_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)
  #define MG_LOG_WARNING(...)  MAGMA_LOG_WARNING_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)
  #define MG_LOG_ERROR(...)    MAGMA_LOG_ERROR_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)
  #define MG_LOG_FATAL(...)    MAGMA_LOG_FATAL_CUSTOM(::Magma::magmaLogger, __VA_ARGS__)

#else
  // #define LOG_TRACE(...)   ::Magma::clientLogger.Log(Magma::Logger::LogType::Trace,   std::source_location::current(), __VA_ARGS__)
  // #define LOG_DEBUG(...)   ::Magma::clientLogger.Log(Magma::Logger::LogType::Debug,   std::source_location::current(), __VA_ARGS__)
  // #define LOG_INFO(...)    ::Magma::clientLogger.Log(Magma::Logger::LogType::Info,    std::source_location::current(), __VA_ARGS__)
  // #define LOG_WARNING(...) ::Magma::clientLogger.Log(Magma::Logger::LogType::Warning, std::source_location::current(), __VA_ARGS__)
  // #define LOG_ERROR(...)   ::Magma::clientLogger.Log(Magma::Logger::LogType::Error,   std::source_location::current(), __VA_ARGS__)
  // #define LOG_FATAL(...)   ::Magma::clientLogger.Log(Magma::Logger::LogType::Fatal,   std::source_location::current(), __VA_ARGS__)

  #define LOG_TRACE(...)    MAGMA_LOG_TRACE_CUSTOM(::Magma::clientLogger, __VA_ARGS__)
  #define LOG_DEBUG(...)    MAGMA_LOG_DEBUG_CUSTOM(::Magma::clientLogger, __VA_ARGS__)
  #define LOG_INFO(...)     MAGMA_LOG_INFO_CUSTOM(::Magma::clientLogger, __VA_ARGS__)
  #define LOG_WARNING(...)  MAGMA_LOG_WARNING_CUSTOM(::Magma::clientLogger, __VA_ARGS__)
  #define LOG_ERROR(...)    MAGMA_LOG_ERROR_CUSTOM(::Magma::clientLogger, __VA_ARGS__)
  #define LOG_FATAL(...)    MAGMA_LOG_FATAL_CUSTOM(::Magma::clientLogger, __VA_ARGS__)

#endif //MAGMA_BUILD

