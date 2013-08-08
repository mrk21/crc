#include <crc/activity/xmtg.hpp>

namespace crc { namespace activity {
#ifdef __TEMPLATE_IMPLEMENTATION__
  template<typename NextActivity> constexpr uint32_t xmtg<NextActivity>::THRESHOLD;
  template<typename NextActivity> constexpr uint32_t xmtg<NextActivity>::FAIL_TIME;
  template<typename NextActivity> constexpr uint32_t xmtg<NextActivity>::RETRY_SIZE;
  
  template<typename NextActivity>
  void xmtg<NextActivity>::start(void) {
    this->clock_count = 0;
    this->retry_count = 0;
    device::clock::start();
    device::ir_xmtr::send();
  }
  
  template<typename NextActivity>
  void xmtg<NextActivity>::stop(void) {
    device::clock::stop();
  }
  
  template<typename NextActivity>
  void xmtg<NextActivity>::on_clock(void) {
    device::indicator::toggle();
    
    if (this->clock_count >= self::FAIL_TIME) {
      if (this->retry_count < self::RETRY_SIZE) {
        ++this->retry_count;
        this->clock_count = 0;
        device::ir_xmtr::send();
      }
      else {
        this->context->transition(util::singleton<error>());
      }
      return;
    }
    
    if (device::light_sensor::get() >= self::THRESHOLD) {
      this->context->transition(util::singleton<self::next_activity>());
    }
    ++this->clock_count;
  }
#endif
}}
