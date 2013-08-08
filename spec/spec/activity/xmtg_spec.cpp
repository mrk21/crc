#include <bandit/bandit.h>
#include <crc/activity/xmtg.hpp>
#include <crc/activity/error.hpp>
#include <crc/activity/base_mock.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  struct xmtg_fixture {
    using xmtg = activity::xmtg<base_mock>;
    xmtg target;
    activity::context context;
    
    xmtg_fixture(void) {
      device::clock::init();
      device::light_sensor::init();
      device::ir_xmtr::init();
      this->context.transition(&this->target, true);
    }
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::xmtg", []{
      xmtg_fixture * fixture;
      before_each([&]{ fixture = new xmtg_fixture(); });
      after_each([&]{ delete fixture; });
      
      it("遷移時に赤外線信号を送信すること", [&]{
        AssertThat(device::ir_xmtr::is_send_, Equals(true));
      });
      
      it("光センサの値がしきい値を超えたら次のアクティビティに遷移すること", [&]{
        device::light_sensor::value_ = xmtg_fixture::xmtg::THRESHOLD;
        fixture->target.on_clock();
        AssertThat(fixture->context.current_activity(), Equals(util::singleton<xmtg_fixture::xmtg::next_activity>()));
      });
      
      it("リトライ上限数を超えたらエラーモードに遷移すること", [&]{
        uint32_t retry_count = 0;
        
        for (uint32_t i=0; i < xmtg_fixture::xmtg::RETRY_SIZE*2; ++i) {
          device::ir_xmtr::is_send_ = false;
          uint32_t fail_count = 0;
          
          for (uint32_t j=0; j < xmtg_fixture::xmtg::FAIL_TIME*2; ++j) {
            fixture->target.on_clock();
            if (device::ir_xmtr::is_send_ || !fixture->target.is_active()) break;
            else ++fail_count;
          }
          AssertThat(fail_count, Equals(xmtg_fixture::xmtg::FAIL_TIME));
          
          if (fixture->context.current_activity() == util::singleton<error>()) break;
          else ++retry_count;
        }
        AssertThat(retry_count, Equals(xmtg_fixture::xmtg::RETRY_SIZE));
      });
    });
  });
}}
