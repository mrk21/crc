#pragma once
#include <LPC11xx.h>

namespace crc { namespace device {
  struct rec_button {
    static void init(void);
    
    template<typename Callback>
    static void on_interrupt(Callback func);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <src/device/rec_button.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
