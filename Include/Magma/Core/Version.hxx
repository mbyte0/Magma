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

#include "Magma/Types.hxx"
#include "fmt/format.h"

namespace Magma {

  struct Version
  {
    Version(UInt16 major, UInt16 minor, UInt16 patch, StringView preReleaseTag, UInt16 preReleaseVersion)
    : major(major), minor(minor), patch(patch), preReleaseTag(preReleaseTag), preReleaseVersion(preReleaseVersion) {}

    String ToString() {
      if (preReleaseTag == "")
        return fmt::format("{}.{}.{}", major, minor, patch);
      if (preReleaseVersion == 0)
        return fmt::format("{}.{}.{}-{}", major, minor, patch, preReleaseTag);
      return fmt::format("{}.{}.{}-{}.{}", major, minor, patch, preReleaseTag, preReleaseVersion);
    }

    UInt16 major, minor, patch;
    String preReleaseTag;
    UInt16 preReleaseVersion;
  };

  Version GetVersion();
  String GetVersionString();

} // namespace Magma
