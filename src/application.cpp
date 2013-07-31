#include <crc/application.hpp>
#include <crc/util.hpp>
#include <crc/io.hpp>
#include <crc/device/uart.hpp>
#include <crc/device/rec_button.hpp>
#include <crc/device/light_sensor.hpp>
#include <crc/device/ir_xmtr.hpp>
#include <crc/device/indicator.hpp>
#include <crc/device/clock.hpp>
#include <crc/activity/standby.hpp>

namespace crc {
  void application::execute(void) {
    device::uart::init();
    device::indicator::init();
    device::light_sensor::init();
    device::ir_xmtr::init();
    device::rec_button::init();
    device::clock::init();
    
    this->transition(util::singleton<activity::standby>(), true);
  }
}
