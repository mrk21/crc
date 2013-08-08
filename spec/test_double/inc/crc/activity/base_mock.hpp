#pragma once
#include <crc/activity/base.hpp>
#include <gmock/gmock.h>

namespace crc { namespace activity {
  class base_mock: public base {
  public:
    MOCK_METHOD0(start, void(void));
    MOCK_METHOD0(stop, void(void));
    MOCK_METHOD0(on_rec_button, void(void));
    MOCK_METHOD0(on_clock, void(void));
  };
}}
