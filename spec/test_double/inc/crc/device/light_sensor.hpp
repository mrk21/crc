#pragma once
#include <cinttypes>

namespace crc { namespace device {
  struct light_sensor {
    using self = light_sensor;
    static uint32_t value_;
    static void init(void);
    static uint32_t get(void);
  };
}}
