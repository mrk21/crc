#include <bandit/bandit.h>
#include <crc/activity/wait.hpp>
#include <crc/activity/base_mock.hpp>
#include <crc/device/clock.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  struct wait_fixture {
    using wait = activity::wait<base_mock>;
    wait target;
    activity::context context;
    
    wait_fixture(void) {
      device::clock::init();
      this->context.transition(&this->target, true);
    }
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::wait", []{
      wait_fixture * fixture;
      before_each([&]{ fixture = new wait_fixture(); });
      after_each([&]{ delete fixture; });
      
      it("1秒たったら次のアクティビティに遷移すること", [&]{
        constexpr uint32_t WAIT_TIME = 10*2;
        uint32_t count = 0;
        
        for (uint32_t i=0; i < WAIT_TIME*2; ++i) {
          fixture->target.on_clock();
          if (fixture->context.current_activity() == util::singleton<wait_fixture::wait::next_activity>()) break;
          else ++count;
        }
        
        ASSERT_EQ(count, WAIT_TIME);
      });
    });
  });
}}
