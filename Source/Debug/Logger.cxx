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

#include "Magma/Debug/Logger.hxx"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Magma {

  std::shared_ptr<spdlog::logger> Logger::s_EngineLogger;
  std::shared_ptr<spdlog::logger> Logger::s_AppLogger;

  void Logger::Initialize() {
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern("%^[%Y-%m-%d %T.%e] [%n] [%l] %s:%# (%!):%$ %v");

    s_EngineLogger = spdlog::stdout_color_mt("Magma");
    s_AppLogger = spdlog::stdout_color_mt("Application");

  }

  void Logger::Shutdown() {
    // TODO
  }

} // namespace Magma
