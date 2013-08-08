#include <crc/device/indicator.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
  void indicator::init(void) {
    LPC_GPIO1->DIR |= (1<<9);
  }
  
  void indicator::on(void) {
    LPC_GPIO1->DATA |= (1<<9);
  }
  
  void indicator::off(void) {
    LPC_GPIO1->DATA &= ~(1<<9);
  }
  
  void indicator::toggle(void) {
    LPC_GPIO1->DATA ^= (1<<9);
  }
}}
