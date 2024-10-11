#include <Magma.hxx>
#include <Magma/EntryPoint.hxx>

class Sandbox : public Magma::Application
{
  void OnUpdate(Float32 delta) override;
};

void Sandbox::OnUpdate(Float32 delta) {
  LOG_DEBUG("message");
}

std::unique_ptr<Magma::Application> CreateApplication() {
  return std::make_unique<Sandbox>();
}
