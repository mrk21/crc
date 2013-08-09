#pragma once

namespace crc { namespace device {
  class rec_button {
  public:
    static void init(void){}
    
    template<typename Callback>
    static void on_interrupt(Callback func){}
  };
}}
