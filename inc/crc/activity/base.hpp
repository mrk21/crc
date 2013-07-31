#pragma once
#include <crc/activity/context.hpp>

namespace crc { namespace activity {
  class base {
  protected:
    activity::context * context;
    bool is_active_;
    
  public:
    base(void);
    
    bool is_active(void);
    void entry(activity::context * context);
    void exit(void);
    
    virtual void start(void);
    virtual void stop(void);
    virtual void on_rec_button(void);
    virtual void on_clock(void);
  };
}}
