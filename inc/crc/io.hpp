#pragma once
#include <cinttypes>

namespace crc {
  struct io {
    static void write(char data);
    static void write(uint32_t data);
    static void write(const char * data);
  };
}
