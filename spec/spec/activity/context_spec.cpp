#include <bandit/bandit.h>
#include <crc/activity/base_mock.hpp>

namespace crc { namespace activity {
  struct context_fixture {
    activity::context context;
  };
  
  go_bandit([]{
    using namespace bandit;
    using namespace testing;
    
    describe("activity::context", []{
      context_fixture * fixture;
      before_each([&]{ fixture = new context_fixture(); });
      after_each([&]{ delete fixture; });
      
      describe("#transition()", [&]{
        describe("immediately = true", [&]{
          it("最初に呼び出した時にきちんと遷移できること", [&]{
            base_mock activity1;
            EXPECT_CALL(activity1, stop()).Times(0);
            EXPECT_CALL(activity1, start()).Times(1);
            fixture->context.transition(&activity1, true);
          });
          
          it("2回目移行に呼び出した時にきちんと遷移できること", [&]{
            base_mock activity1;
            fixture->context.transition(&activity1, true);
            
            base_mock activity2;
            EXPECT_CALL(activity1, stop()).Times(1);
            EXPECT_CALL(activity2, start()).Times(1);
            fixture->context.transition(&activity2, true);
          });
        });
        
        describe("immediately = false", [&]{
          it("最初に呼び出した時にきちんと遷移できること", [&]{
            base_mock activity1;
            EXPECT_CALL(activity1, stop()).Times(0);
            EXPECT_CALL(activity1, start()).Times(0);
            fixture->context.transition(&activity1);
          });
          
          it("2回目移行に呼び出した時にきちんと遷移できること", [&]{
            base_mock activity1;
            fixture->context.transition(&activity1, true);
            
            base_mock activity2;
            EXPECT_CALL(activity1, stop()).Times(1);
            EXPECT_CALL(activity2, start()).Times(0);
            fixture->context.transition(&activity2);
          });
        });
      });
      
      describe("#on_clock()", [&]{
        it("アクティビティのon_clock()が呼ばれること", [&]{
          base_mock activity1;
          fixture->context.transition(&activity1);
          
          EXPECT_CALL(activity1, stop()).Times(0);
          EXPECT_CALL(activity1, on_clock()).Times(1);
          fixture->context.on_clock();
        });
        
        it("アクティビティのon_clock()内で状態遷移した場合、終了処理と次のアクティビティの開始処理が呼ばれること", [&]{
          base_mock activity1;
          fixture->context.transition(&activity1);
          
          base_mock activity2;
          EXPECT_CALL(activity2, start()).Times(1);
          EXPECT_CALL(activity1, stop()).Times(1);
          EXPECT_CALL(activity1, on_clock()).Times(1).WillOnce(Invoke([&]{
            fixture->context.transition(&activity2);
          }));
          fixture->context.on_clock();
        });
      });
    });
  });
}}
