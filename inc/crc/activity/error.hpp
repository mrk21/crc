#pragma once
#include <crc/activity/base.hpp>
#include <cinttypes>

namespace crc { namespace activity {
  class error: public base {
  public:
    using self = error;
    static constexpr uint32_t TOGGLE_INTERVAL = 5*2;
    
  protected:
    uint32_t clock_count;
    
  public:
    virtual void start(void);
    virtual void stop(void);
    virtual void on_rec_button(void);
    virtual void on_clock(void);
  };
}}
