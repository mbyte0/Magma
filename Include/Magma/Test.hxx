#pragma once

#include "Magma/Types.hxx"

namespace Magma {

  void MAGMA_API TestFunc();

  class MAGMA_API TestClass
  {
  public:
    TestClass(Int32 num) :m_Number(num) {}

    Int32 GetNumber();
    void SetNumber(Int32 num);

  private:
    Int32 m_Number = 6;

  };

} // namespace Magma
