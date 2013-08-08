#pragma once

namespace crc { namespace device {
  struct rec_button {
    static void init(void);
    
    template<typename Callback>
    static void on_interrupt(Callback func);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <device/rec_button.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
