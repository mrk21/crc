#include <crc/device/indicator.hpp>

namespace crc { namespace device {
  bool indicator::is_on_;
  
  void indicator::init(void) { self::off(); }
  void indicator::on(void) { self::is_on_ = true; }
  void indicator::off(void) { self::is_on_ = false; }
  void indicator::toggle(void) { self::is_on_ = !self::is_on_; }
}}
