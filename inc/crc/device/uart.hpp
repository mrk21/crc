#pragma once

namespace crc { namespace device {
  class uart {
  protected:
    static constexpr auto BAUDRATE = 9600;
    
  public:
    static void init(void);
    static void write(char data);
  };
}}
