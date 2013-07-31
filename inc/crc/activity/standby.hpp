#pragma once
#include <crc/activity/base.hpp>

namespace crc { namespace activity {
  class standby: public base {
  public:
    virtual void start(void);
    virtual void on_rec_button(void);
  };
}}
