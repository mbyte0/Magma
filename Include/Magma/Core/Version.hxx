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
