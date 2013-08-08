#include <bandit/bandit.h>
#include <crc/device/uart.hpp>
#include <crc/io.hpp>
#include <string>

namespace crc {
  go_bandit([]{
    using namespace bandit;
    
    describe("io", []{
      before_each([]{
        device::uart::init();
      });
      
      describe("::write()", []{
        it("文字列が出力されること", []{
          std::string value = "hoge";
          io::write(value.c_str());
          AssertThat(device::uart::buffer_, Equals(value));
        });
        
        it("数値が出力されること", []{
          uint32_t value = 123;
          std::string value_str = "123";
          io::write(value);
          AssertThat(device::uart::buffer_, Equals(value_str));
        });
      });
    });
  });
}
