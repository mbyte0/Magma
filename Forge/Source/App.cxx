#include <iostream>
#include "App.hxx"

App::App(std::string_view name)
: m_Name(name) {}

void App::Print(std::string_view sv) {
  std::cout << "[" << m_Name << "] " << sv << std::endl;
}
