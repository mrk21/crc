#pragma once
#include <crc/activity/base.hpp>
#include <crc/activity/record.hpp>
#include <crc/activity/xmtg.hpp>

namespace crc { namespace activity {
  class standby: public base {
  public:
    using self = standby;
    virtual void start(void);
    virtual void on_rec_button(void);
  };
}}
