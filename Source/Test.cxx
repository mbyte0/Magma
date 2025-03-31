#include "Magma/Test.hxx"

#include <iostream>

namespace Magma {

  void TestFunc() {
    std::cout << "Test function" << std::endl;
  }

  Int32 TestClass::GetNumber() {
    return m_Number;
  }

  void TestClass::SetNumber(Int32 num) {
    m_Number = num;
  }

} // namespace Magma
