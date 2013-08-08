#pragma once
#include <cinttypes>
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
  public:
    using self = xmtg;
    using next_activity = NextActivity;
    
    static constexpr uint32_t THRESHOLD = 600;
    static constexpr uint32_t FAIL_TIME = 10*10*2;
    static constexpr uint32_t RETRY_SIZE = 2;
    
  protected:
    uint32_t clock_count;
    uint32_t retry_count;
    
  public:
    virtual void start(void);
    virtual void stop(void);
    virtual void on_clock(void);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <activity/xmtg.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
