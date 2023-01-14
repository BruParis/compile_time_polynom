#pragma once

#include <iostream>
#include <type_traits>

using coeff = int;

template <typename... Args>
constexpr size_t num_args(Args...) {
  return sizeof...(Args);
}

template <coeff... C>
struct PX {
  static constexpr size_t o = num_args(C...) - 1;
};
// std::enable_if < std::conjunction_v < std::is_scalar < C...>>

// template <coeff... C>
// std::ostream &operator<<(std::ostream &os, PX<C...> p);
template <coeff First, coeff... C>
std::ostream &operator<<(std::ostream &os, PX<First, C...> p) {
  if (First == 0) {
    os << PX<C...>();
    return os;
  }

  if (PX<First, C...>::o > 1) {
    os << First << ".X^" << PX<First, C...>::o << " ";
  } else {
    os << First << ".X ";
  }

  os << PX<C...>();
  return os;
}
template <coeff Last>
std::ostream &operator<<(std::ostream &os, PX<Last> p) {
  if (Last != 0) {
    os << Last;
  }
  return os;
}

template <coeff C, class PX>
struct _push;
template <coeff New, coeff... C>
struct _push<New, PX<C...>> {
  using type = PX<New, C...>;
};

// order comparison
// _greater -> P0 > p1
/*template <class P0, class P1>
struct _greater {
  using type = std::greater<P0::o, P1::o>::type;
};*/

// addition
/*template <class P0, class P1>
struct _add;
template <coeff First0, coeff... C0, coeff First1, coeff... C1>
struct _add<PX<First0, C0...>, PX<First1, C1...>> {
  using type = typename std::conditional<
      PX<First0, C0...>::o >= PX<First1, C1...>::o,
      _push<First0, _add<PX<C0...>, PX<First1, C1...>>::type>::type,
      _push<First1, _add<PX<First0, C0...>, PX<C1...>>::type>::type>::type;
};

template <class P0, class P1>
constexpr typename _add<P0, P1>::type operator+(P0 p0, P1 p1) {
  return {};
}*/

// Multilpication -> Strassen matrix
