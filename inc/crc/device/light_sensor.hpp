#pragma once
#include <LPC11xx.h>

namespace crc { namespace device {
  struct light_sensor {
    static void init(void);
    static uint32_t get(void);
  };
}}
