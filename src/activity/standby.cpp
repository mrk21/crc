#include <crc/activity/standby.hpp>
#include <crc/activity/record.hpp>
#include <crc/activity/xmtg.hpp>
#include <crc/device/indicator.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  void standby::start(void) {
    device::indicator::on();
  }
  
  void standby::on_rec_button(void) {
    this->context->transition(util::singleton<xmtg<record>>());
  }
}}
