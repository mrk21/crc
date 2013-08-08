#pragma once

namespace crc { namespace device {
  struct indicator {
    using self = indicator;
    static bool is_on_;
    
    static void init(void);
    static void on(void);
    static void off(void);
    static void toggle(void);
  };
}}
