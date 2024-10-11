#include "Lib.hxx"
#include "App.hxx"

int main() {
  App app("app name");
  app.Print(Lib::GetVersion());
}
