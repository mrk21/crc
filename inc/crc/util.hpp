#pragma once
#include <cinttypes>

namespace crc { namespace util {
  constexpr int32_t round_impl(double v, int32_t iv) {
    return (v - iv) < 0.49999 ? iv : iv+1;
  }
  
  constexpr int32_t round(double v) {
    return round_impl(v, static_cast<int32_t>(v));
  }
  
  
  constexpr int32_t ceil_impl(double v, int32_t iv) {
    return (v - iv) < 0.00001 ? iv : iv+1;
  }
  
  constexpr int32_t ceil(double v) {
    return ceil_impl(v, static_cast<int32_t>(v));
  }
  
  
  constexpr int32_t floor(double v) {
    return static_cast<int32_t>(v);
  }
  
  
  template<class Class>
  Class * singleton(void) {
    static Class instance;
    return &instance;
  }
}}
