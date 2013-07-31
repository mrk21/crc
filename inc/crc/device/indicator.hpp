#pragma once
#include <LPC11xx.h>

namespace crc { namespace device {
  class indicator {
    using self = indicator;
    
  public:
    static void init(void);
    static void on(void);
    static void off(void);
    static void toggle(void);
  };
}}
