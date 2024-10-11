#include "Magma/Core/Version.hxx"

namespace Magma {

  Version GetVersion() {
    return Version(MAGMA_VERSION_MAJOR, MAGMA_VERSION_MINOR, MAGMA_VERSION_PATCH, MAGMA_VERSION_PRE_RELEASE_TAG, MAGMA_VERSION_PRE_RELEASE_VERSION);
  }

  String GetVersionString() {
    return String(MAGMA_VERSION_STRING);
  }

} // namespace Magma
