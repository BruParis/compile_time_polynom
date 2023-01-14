#pragma once

#include <iostream>
#include <type_traits>

#include "rational.h"

template <unsigned int O, int p, unsigned int q = 1>
struct Xn {};
template <unsigned int O, int p, unsigned int q = 1>
std::ostream &operator<<(std::ostream &os, Xn<O, p, q> m) {
  os << rational<p, q>();
  if (O == 0) {
    return os;
  }

  if (O == 1) {
    os << ".X";
    return os;
  }
  os << ".X^" << O;
  return os;
}