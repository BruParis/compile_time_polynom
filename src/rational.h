#pragma once

#include <iostream>
#include <type_traits>

template <unsigned int a, unsigned int b, typename cond = void>
struct _gcd_aux;

template <unsigned int a, unsigned int b>
struct _gcd_aux<a, b, typename std::enable_if<b == 0>::type> {
  static constexpr auto val = a;
};

template <unsigned int a, unsigned int b>
struct _gcd_aux<a, b, typename std::enable_if<b >= 1>::type> {
  static constexpr auto val = _gcd_aux<b, a - (a / b) * b>::val;
};

template <int a, unsigned int b>
struct gcd {
  static_assert(b != 0);
  static constexpr auto val = _gcd_aux<abs(a), b>::val;
};

template <bool pos, unsigned int p, unsigned int q>
struct quot {};

template <bool pos, unsigned int p, unsigned int q>
constexpr std::ostream &operator<<(std::ostream &os, quot<pos, p, q> r) {
  if (!pos) {
    os << "-";
  }

  os << p;
  if (q != 1) {
    os << "/" << q;
  }

  return os;
}

template <bool pos, unsigned int p, unsigned int q, bool _>
struct _rat_aux2 {};

template <bool pos, unsigned int p, unsigned int q>
struct _rat_aux {
  using type = typename _rat_aux2<pos, p, q, gcd<p, q>::val == 1>::type;
};

template <bool pos, unsigned int p, unsigned int q>
struct _rat_aux2<pos, p, q, true> {
  using type = quot<pos, p, q>;
};
template <bool pos, unsigned int p, unsigned int q>
struct _rat_aux2<pos, p, q, false> {
  using type =
      typename _rat_aux<pos, p / gcd<p, q>::val, q / gcd<p, q>::val>::type;
};

template <int p, int q>
using rational = typename _rat_aux<(p * q) >= 0, abs(p), abs(q)>::type;