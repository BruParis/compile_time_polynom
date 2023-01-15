#include <string>

#include "monom.h"
#include "polynomial.h"

int main() {
  gcd<11, 17>();
  gcd<17, 11>();

  int gcd17_11 = gcd<17, 11>::val;
  std::cout << "gcd 17 - 11: " << gcd17_11 << "\n";

  int gcd36_6 = gcd<36, 6>::val;
  std::cout << "gcd36_6: " << gcd36_6 << "\n";

  int gcd6_1 = gcd<6, 1>::val;
  std::cout << "gcd6_1: " << gcd6_1 << "\n";

  rational<36, 6>();
  static_assert(std::is_same<rational<36, 6>, rational<6, 1>>::value);

  std::cout << rational<36, 6>() << "\n";
  std::cout << rational<6, 1>() << "\n";
  std::cout << rational<-6, 1>() << "\n";
  std::cout << rational<-6, -1>() << "\n";
  std::cout << rational<17, 11>() << "\n";
  std::cout << rational<11, 17>() << "\n";

  // std::cout << Xn<6, 6>() << "\n";
  // std::cout << Xn<6, 36, 6>() << "\n";
  // std::cout << Xn<6, 11, 17>() << "\n";
  // std::cout << Xn<1, 11, 17>() << "\n";
  // std::cout << Xn<0, 11, 17>() << "\n";
  // std::cout << Xn<1, 6, 3>() << "\n";
  // std::cout << Xn<rational<11, 77>, 8> << "\n";

  // Monoms
  // MX<6, 4>();

  // Poly<2, 3> t;n
  /*std::cout << "Hello world!\n";
  size_t n = num_args(4, 5, 6.9, 10);
  std::cout << n << "\n";
  std::cout << PX<4, 5, 6, 'a'>() << "\n";
  std::cout << PX<4, 5, 6, 10>() << "\n";
  std::cout << PX<4, 0, 6, 10>() << "\n";
  std::cout << PX<0, 0, 0, 3>() << "\n";

  std::cout << _push<3, PX<4, 0, 0, 3>>::type() << "\n";*/

  // std::cout << PX<1,2>() + PX<3,4>() << "\n";
}