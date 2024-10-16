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

#include "Magma/Core/Application.hxx"

namespace Magma {

  Application::Application() {

  }

  Application::~Application() {

  }

  void Application::Run() {
    while (m_Runing) {
      // TODO: Add delta time
      OnUpdate(0.0f);
    }
  }

} // namespace Magma
