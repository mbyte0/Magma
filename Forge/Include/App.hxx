#pragma once

#include <string>
#include <string_view>

class App
{
public:
  App(std::string_view name);
  void Print(std::string_view sv);

private:
  std::string m_Name;

};
