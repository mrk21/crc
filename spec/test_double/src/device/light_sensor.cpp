#include <crc/device/light_sensor.hpp>

namespace crc { namespace device {
  uint32_t light_sensor::value_;
  
  void light_sensor::init(void) {
    self::value_ = 0;
  }
  
  uint32_t light_sensor::get(void) {
    return self::value_;
  }
}}
