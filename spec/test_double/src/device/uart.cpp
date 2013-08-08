#include <crc/device/uart.hpp>

namespace crc { namespace device {
  std::string uart::buffer_;
  
  void uart::init(void) {
    self::buffer_.erase();
  }
  
  void uart::write(char data) {
    self::buffer_ += data;
  }
}}
