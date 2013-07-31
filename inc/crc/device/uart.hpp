#pragma once
#include <LPC11xx.h>

namespace crc { namespace device {
  struct uart {
    static constexpr auto BAUDRATE = 9600;
    
    static void init(void);
    static void write(char data);
  };
}}
