#include <crc/activity/record.hpp>
#include <crc/activity/standby.hpp>
#include <crc/device/indicator.hpp>
#include <crc/device/ir_xmtr.hpp>
#include <crc/device/light_sensor.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  constexpr uint32_t record::TOGGLE_INTERVAL;
  constexpr uint32_t record::RECORD_INTERVAL;
  
  void record::start(void) {
    this->clock_count = 0;
    device::clock::start();
  }
  
  void record::stop(void) {
    device::clock::stop();
  }
  
  void record::on_rec_button(void) {
    this->context->transition(util::singleton<xmtg<standby>>());
  }
  
  void record::on_clock(void) {
    ++this->clock_count;
    
    if (this->clock_count % self::TOGGLE_INTERVAL == 0) {
      device::indicator::toggle();
    }
    
    if (this->clock_count > self::RECORD_INTERVAL) {
      this->context->transition(util::singleton<xmtg<wait<xmtg<record>>>>());
    }
  }
}}
