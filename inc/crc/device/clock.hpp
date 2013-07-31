#pragma once
#include <LPC11xx.h>

namespace crc { namespace device {
  struct clock {
    static void init(void);
    static void start(void);
    static void stop(void);
    
    template<typename Callback>
    static void on_interrupt(Callback callback);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <src/device/clock.cpp>
#undef __TEMPLATE_IMPLEMENTATION__