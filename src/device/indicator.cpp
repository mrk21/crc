#include <crc/device/indicator.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
  constexpr uint32_t indicator::BIT;
  
  void indicator::init(void) {
    LPC_GPIO1->DIR |= self::BIT;
  }
  
  void indicator::on(void) {
    LPC_GPIO1->DATA |= self::BIT;
  }
  
  void indicator::off(void) {
    LPC_GPIO1->DATA &= ~self::BIT;
  }
  
  void indicator::toggle(void) {
    LPC_GPIO1->DATA ^= self::BIT;
  }
}}
