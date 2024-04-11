#ifndef __TERNARY_H__
#define __TERNARY_H__

/*
 support ternary numbers, eg:
 int a = 102_ter;
 int b = -1001_ter;

 https://github.com/zhao-xiaogang/cpp_ternary
*/

namespace ternary_impl {

  template<int N> constexpr int three_power() { return three_power<N-1>() * 3; }
  template<> constexpr int three_power<0>() { return 1; }

  template<char A, char... B> constexpr int to_ternary() {
    static_assert('0'<=A && A<='2', "Illegal ternary character");
    return (A - '0') * three_power<sizeof...(B)>() + to_ternary<B...>();
  }

  template<> constexpr int to_ternary<'0'>() { return 0; }
  template<> constexpr int to_ternary<'1'>() { return 1; }
  template<> constexpr int to_ternary<'2'>() { return 2; }
}

template<char... C> constexpr int operator "" _ter() { return ternary_impl::to_ternary<C...>(); }

#endif
