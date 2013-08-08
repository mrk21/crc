#include <crc/device/clock.hpp>

namespace crc { namespace device {
  bool clock::is_start_;
  
  void clock::init(void) {
    self::stop();
  }
  
  void clock::start(void) { self::is_start_ = true; }
  void clock::stop(void) { self::is_start_ = false; }
}}
