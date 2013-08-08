#include <bandit/bandit.h>
#include <crc/activity/base_mock.hpp>

namespace crc { namespace activity {
  struct base_fixture {
    base_mock target;
    activity::context context;
  };
  
  go_bandit([]{
    using namespace bandit;
    
    describe("activity::base", []{
      base_fixture * fixture;
      before_each([&]{ fixture = new base_fixture(); });
      after_each([&]{ delete fixture; });
      
      describe("#entry()", [&]{
        it("アクティビティの初期化ができること", [&]{
          EXPECT_CALL(fixture->target, start()).Times(1);
          
          AssertThat(fixture->target.is_active(), Equals(false));
          fixture->target.entry(&fixture->context);
          AssertThat(fixture->target.is_active(), Equals(true));
        });
      });
      
      describe("#exit()", [&]{
        it("アクティビティの後処理ができること", [&]{
          fixture->target.entry(&fixture->context);
          EXPECT_CALL(fixture->target, stop()).Times(1);
          
          AssertThat(fixture->target.is_active(), Equals(true));
          fixture->target.exit();
          AssertThat(fixture->target.is_active(), Equals(false));
        });
      });
    });
  });
}}
