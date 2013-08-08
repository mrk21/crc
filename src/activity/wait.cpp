#include <crc/activity/wait.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
#ifdef __TEMPLATE_IMPLEMENTATION__
  template<typename NextActivity>
  constexpr uint32_t wait<NextActivity>::WAIT_TIME;
  
  template<typename NextActivity>
  void wait<NextActivity>::start(void) {
    this->clock_count = 0;
    device::clock::start();
  }
  
  template<typename NextActivity>
  void wait<NextActivity>::stop(void) {
    device::clock::stop();
  }
  
  template<typename NextActivity>
  void wait<NextActivity>::on_clock(void) {
    if (this->clock_count >= self::WAIT_TIME) {
      this->context->transition(util::singleton<self::next_activity>());
    }
    ++this->clock_count;
  }
#endif
}}
