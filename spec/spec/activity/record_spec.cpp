#include <bandit/bandit.h>
#include <crc/activity/standby.hpp>
#include <crc/activity/record.hpp>
#include <crc/activity/xmtg.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  struct record_fixture {
    record target;
    activity::context context;
    
    record_fixture(void) {
      device::clock::init();
      this->context.transition(&this->target, true);
    }
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::record", []{
      record_fixture * fixture;
      before_each([&]{ fixture = new record_fixture(); });
      after_each([&]{ delete fixture; });
      
      it("遷移時にクロックが供給されていること", [&]{
        AssertThat(device::clock::is_start_, Equals(true));
      });
      
      it("終了時にクロックが停止していること", [&]{
        fixture->target.stop();
        AssertThat(device::clock::is_start_, Equals(false));
      });
      
      it("録画ボタンが押されたら待機モードに遷移すること", [&]{
        fixture->target.on_rec_button();
        AssertThat(fixture->context.current_activity(), Equals(util::singleton<xmtg<standby>>()));
      });
      
      it("録画時間が10分を超えたら停止して再度録画すること", [&]{
        constexpr uint32_t MAX_COUNT = 10*60*10*2; // 10 min
        uint32_t count = 0;
        
        for (uint32_t i=0;  i < MAX_COUNT*2; ++i) {
          fixture->target.on_clock();
          if (fixture->context.current_activity() == util::singleton<xmtg<wait<xmtg<record>>>>()) break;
          else ++count;
        }
        
        AssertThat(count, Equals(MAX_COUNT));
      });
    });
  });
}}
