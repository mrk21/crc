#pragma once
#include <string>

namespace crc { namespace device {
  struct uart {
    using self = uart;
    static std::string buffer_;
    static void init(void);
    static void write(char data);
  };
}}
