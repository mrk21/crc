#pragma once
#include <cinttypes>

namespace crc { namespace device {
  class indicator {
  protected:
    using self = indicator;
    static constexpr uint32_t BIT = (1<<9);
    
  public:
    static void init(void);
    static void on(void);
    static void off(void);
    static void toggle(void);
  };
}}
