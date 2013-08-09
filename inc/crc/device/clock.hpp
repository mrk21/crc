#pragma once
#include <cinttypes>

namespace crc { namespace device {
  class clock {
  protected:
    using self = clock;
    static constexpr uint32_t IR_BIT = 1<<2;
    
  public:
    static void init(void);
    static void start(void);
    static void stop(void);
    
    template<typename Callback>
    static void on_interrupt(Callback callback);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <device/clock.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
