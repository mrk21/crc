#include <bandit/bandit.h>
#include <crc/activity/standby.hpp>
#include <crc/activity/record.hpp>
#include <crc/activity/xmtg.hpp>
#include <crc/device/indicator.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  struct standby_fixture {
    standby target;
    activity::context context;
    
    standby_fixture(void) {
      device::indicator::init();
      this->context.transition(&this->target, true);
    }
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::standby", []{
      standby_fixture * fixture;
      before_each([&]{ fixture = new standby_fixture(); });
      after_each([&]{ delete fixture; });
      
      it("遷移時にインジケータが点灯していること", [&]{
        AssertThat(device::indicator::is_on_, Equals(true));
      });
      
      it("録画ボタンが押されたら録画モードへ遷移すること", [&]{
        fixture->target.on_rec_button();
        AssertThat(fixture->context.current_activity(), Equals(util::singleton<xmtg<record>>()));
      });
    });
  });
}}
