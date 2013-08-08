#include <bandit/bandit.h>
#include <crc/util.hpp>

namespace crc { namespace util {
  namespace {
    struct singleton_type {
      static bool initialized;
      singleton_type(void) { initialized = true; }
    };
    bool singleton_type::initialized = false;
  }
  
  go_bandit([]{
    using namespace bandit;
    
    describe("util", []{
      describe("::floor()", []{
        it("小数点以下は切り捨てること", []{
          AssertThat(floor(1.0), Equals(1));
          AssertThat(floor(1.2), Equals(1));
          AssertThat(floor(1.5), Equals(1));
          AssertThat(floor(1.7), Equals(1));
          AssertThat(floor(2.0), Equals(2));
        });
      });
      
      describe("::ceil()", []{
        it("小数点以下は切り上げること", []{
          AssertThat(ceil(1.0), Equals(1));
          AssertThat(ceil(1.2), Equals(2));
          AssertThat(ceil(1.5), Equals(2));
          AssertThat(ceil(1.7), Equals(2));
          AssertThat(ceil(2.0), Equals(2));
        });
      });
      
      describe("::round()", []{
        it("小数点以下は四捨五入すること", []{
          AssertThat(round(1.0), Equals(1));
          AssertThat(round(1.2), Equals(1));
          AssertThat(round(1.5), Equals(2));
          AssertThat(round(1.7), Equals(2));
          AssertThat(round(2.0), Equals(2));
        });
      });
      
      describe("::singleton()", []{
        it("最初に呼び出されるまでコンストラクタが実行されないこと", []{
          AssertThat(singleton_type::initialized, Equals(false));
          singleton_type * ptr = singleton<singleton_type>();
          AssertThat(singleton_type::initialized, Equals(true));
          
          AssertThat(ptr, Equals(singleton<singleton_type>()));
          AssertThat(ptr, Equals(singleton<singleton_type>()));
        });
      });
    });
  });
}}
