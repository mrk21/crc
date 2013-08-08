#include <crc/activity/error.hpp>
#include <crc/activity/standby.hpp>
#include <crc/device/indicator.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  constexpr uint32_t error::TOGGLE_INTERVAL;
  
  void error::start(void) {
    this->clock_count = 0;
    device::clock::start();
  }
  
  void error::stop(void) {
    device::clock::stop();
  }
  
  void error::on_rec_button(void) {
    this->context->transition(util::singleton<standby>());
  }
  
  void error::on_clock(void) {
    if (++this->clock_count == self::TOGGLE_INTERVAL) {
      this->clock_count = 0;
      device::indicator::toggle();
    }
  }
}}
