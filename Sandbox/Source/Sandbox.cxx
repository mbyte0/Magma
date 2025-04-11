#include <Magma.hxx>

int main() {
  Magma::Initialize();

  LOG_INFO("Added {1} to {0}", "Magma", "logger");

  Magma::Shutdown();
}
