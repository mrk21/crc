#pragma once
#include <cinttypes>

namespace crc { namespace device {
  class light_sensor {
  public:
    static void init(void);
    static uint32_t get(void);
  };
}}
