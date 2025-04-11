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

#include "Magma/Types.hxx"

#define SPDLOG_FUNCTION __PRETTY_FUNCTION__
#include "spdlog/spdlog.h"

namespace Magma {

  class MAGMA_API Logger
  {
  public:
    Logger() = delete;

    static void Initialize();
    static void Shutdown();

    inline static const std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
    inline static const std::shared_ptr<spdlog::logger>& GetAppLogger()    { return s_AppLogger;    }

  private:
    static std::shared_ptr<spdlog::logger> s_EngineLogger;
    static std::shared_ptr<spdlog::logger> s_AppLogger;

  };

} // namespace Magma


// Prevents Application from using the engine's loggnig macros
#if MAGMA_BUILD
  #define MG_LOG_TRACE(...)      SPDLOG_LOGGER_TRACE(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
  #define MG_LOG_DEBUG(...)      SPDLOG_LOGGER_DEBUG(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
  #define MG_LOG_INFO(...)       SPDLOG_LOGGER_INFO(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
  #define MG_LOG_WARN(...)       SPDLOG_LOGGER_WARN(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
  #define MG_LOG_ERROR(...)      SPDLOG_LOGGER_ERROR(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
  #define MG_LOG_CRITICAL(...)   SPDLOG_LOGGER_CRITICAL(::Magma::Logger::GetEngineLogger(), __VA_ARGS__)
#else
  #define LOG_TRACE(...)         SPDLOG_LOGGER_TRACE(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
  #define LOG_DEBUG(...)         SPDLOG_LOGGER_DEBUG(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
  #define LOG_INFO(...)          SPDLOG_LOGGER_INFO(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
  #define LOG_WARN(...)          SPDLOG_LOGGER_WARN(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
  #define LOG_ERROR(...)         SPDLOG_LOGGER_ERROR(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
  #define LOG_CRITICAL(...)      SPDLOG_LOGGER_CRITICAL(::Magma::Logger::GetAppLogger(), __VA_ARGS__)
#endif // MAGMA_BUILD
