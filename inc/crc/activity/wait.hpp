#pragma once
#include <crc/activity/base.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  template<typename NextActivity>
  class wait: public base {
    using self = wait;
    using next_activity = NextActivity;
    
    static constexpr auto WAIT_TIME = 1*10*2;
    uint32_t clock_count;
    
  public:
    virtual void start(void) {
      this->clock_count = 0;
      device::clock::start();
    }
    
    virtual void stop(void) {
      device::clock::stop();
    }
    
    virtual void on_clock(void) {
      ++this->clock_count;
      
      if (this->clock_count >= self::WAIT_TIME) {
        this->context->transition(util::singleton<self::next_activity>());
      }
    }
  };
}}
