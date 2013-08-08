#pragma once
#include <cinttypes>

namespace crc { namespace device {
  struct ir_xmtr {
    using self = ir_xmtr;
    static bool is_send_;
    
    static void init(void);
    static void send(void);
    static void on_interrupt(void);
  };
}}
