#pragma once

namespace crc { namespace device {
  class indicator {
  public:
    using self = indicator;
    static bool is_on_;
    
    static void init(void);
    static void on(void);
    static void off(void);
    static void toggle(void);
  };
}}
