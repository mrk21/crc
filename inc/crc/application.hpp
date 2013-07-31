#pragma once
#include <crc/activity/context.hpp>

namespace crc {
  class application: public activity::context {
  public:
    void execute(void);
  };
}
