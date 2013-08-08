#pragma once

namespace crc { namespace activity {
  struct base;
  
  class context {
  protected:
    activity::base * current_activity_;
    
  public:
    context(void);
    activity::base * current_activity(void);
    void transition(activity::base * next, bool immediately = false);
    void on_rec_button(void);
    void on_clock(void);
  };
}}
