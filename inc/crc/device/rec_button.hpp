#pragma once
#include <cinttypes>

namespace crc { namespace device {
  class rec_button {
  protected:
    using self = rec_button;
    static constexpr uint32_t BIT = 1<<8;
    
  public:
    static void init(void);
    
    template<typename Callback>
    static void on_interrupt(Callback func);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <device/rec_button.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
