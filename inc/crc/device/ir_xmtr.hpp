#pragma once
#include <cinttypes>

namespace crc { namespace device {
  class ir_xmtr {
    using self = ir_xmtr;
    
    static constexpr uint8_t SIGNAL[] = {1,0,0,0,0,0,0,0,0,0,1};
    static constexpr uint32_t SIGNAL_SIZE = sizeof(SIGNAL) / sizeof(*SIGNAL);
    static constexpr uint32_t TRANSMIT_SIZE = 23*2;
    
    static uint32_t irq_count;
    static uint32_t signal_count;
    
  public:
    static void init(void);
    static void send(void);
    static void on_interrupt(void);
    
  private:
    static void stop(void);
    static void on(void);
    static void off(void);
  };
}}
