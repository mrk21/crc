#pragma once
#include <cinttypes>
#include <crc/activity/base.hpp>

namespace crc { namespace activity {
  template<typename NextActivity>
  class wait: public base {
  public:
    using self = wait;
    using next_activity = NextActivity;
    static constexpr uint32_t WAIT_TIME = 1*10*2;
    
  protected:
    uint32_t clock_count;
    
  public:
    virtual void start(void);
    virtual void stop(void);
    virtual void on_clock(void);
  };
}}

#define __TEMPLATE_IMPLEMENTATION__
#include <activity/wait.cpp>
#undef __TEMPLATE_IMPLEMENTATION__
