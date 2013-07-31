#pragma once
#include <cinttypes>
#include <crc/activity/base.hpp>
#include <crc/activity/xmtg.hpp>
#include <crc/activity/wait.hpp>

namespace crc { namespace activity {
  class record: public base {
    using self = record;
    using next_activity = activity::xmtg<activity::xmtg<activity::record>>;
    
    static constexpr uint32_t TOGGLE_INTERVAL = 2*10*2;
    static constexpr uint32_t RECORD_INTERVAL = 10*60*10*2;
    uint32_t clock_count;
    
  public:
    virtual void start(void);
    virtual void stop(void);
    virtual void on_rec_button(void);
    virtual void on_clock(void);
  };
}}
