#pragma once

namespace crc { namespace device {
  struct clock {
    using self = clock;
    static bool is_start_;
    
    static void init(void);
    static void start(void);
    static void stop(void);
    
    template<typename Callback>
    static void on_interrupt(Callback callback) {}
  };
}}
