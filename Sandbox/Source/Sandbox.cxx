#include <Magma.hxx>

#include <iostream>


int main() {
  Magma::TestFunc();

  Magma::TestClass a(456);
  std::cout << "Number first value: " << a.GetNumber() << std::endl;
  a.SetNumber(987);
  std::cout << "Number: " << a.GetNumber() << std::endl;

  for (Size i = 0; i <= 100; i++) {
    std::cout << "i is: " << i << std::endl;
    a.SetNumber(i);
  }
}
