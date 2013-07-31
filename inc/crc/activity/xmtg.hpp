#pragma once
#include <crc/activity/base.hpp>
#include <crc/activity/error.hpp>
#include <crc/device/indicator.hpp>
#include <crc/device/ir_xmtr.hpp>
#include <crc/device/light_sensor.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  template<typename NextActivity>
  class xmtg: public base {
    using self = xmtg;
    using next_activity = NextActivity;
    
    static constexpr uint32_t THRESHOLD = 600;
    static constexpr uint32_t FAIL_TIME = 10*10*2;
    static constexpr uint32_t RETRY_SIZE = 2;
    
    uint32_t clock_count;
    uint32_t retry_count;
    
  public:
    virtual void start(void) {
      this->clock_count = 0;
      this->retry_count = 0;
      device::clock::start();
      device::ir_xmtr::send();
    }
    
    virtual void stop(void) {
      device::clock::stop();
    }
    
    virtual void on_clock(void) {
      ++this->clock_count;
      device::indicator::toggle();
      
      if (this->clock_count >= self::FAIL_TIME) {
        if (this->retry_count++ < self::RETRY_SIZE) {
          this->clock_count = 0;
          device::ir_xmtr::send();
        }
        else {
          this->context->transition(util::singleton<activity::error>());
          return;
        }
      }
      
      if (device::light_sensor::get() > self::THRESHOLD) {
        this->context->transition(util::singleton<self::next_activity>());
      }
    }
  };
}}
