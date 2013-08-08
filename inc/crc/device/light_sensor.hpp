#pragma once
#include <cinttypes>

namespace crc { namespace device {
  struct light_sensor {
    static void init(void);
    static uint32_t get(void);
  };
}}
