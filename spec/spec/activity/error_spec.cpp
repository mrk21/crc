#include <bandit/bandit.h>
#include <crc/activity/error.hpp>
#include <crc/activity/standby.hpp>
#include <crc/util.hpp>

namespace crc { namespace activity {
  struct error_fixture {
    error target;
    activity::context context;
    
    error_fixture(void) {
      this->context.transition(&this->target, true);
    }
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::error", []{
      error_fixture * fixture;
      before_each([&]{ fixture = new error_fixture(); });
      after_each([&]{ delete fixture; });
      
      it("録画ボタンが押されたら待機モードへ遷移すること", [&]{
        fixture->target.on_rec_button();
        AssertThat(fixture->context.current_activity(), Equals(util::singleton<standby>()));
      });
    });
  });
}}
