#include <crc/device/rec_button.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
#ifndef __TEMPLATE_IMPLEMENTATION__
  constexpr uint32_t rec_button::BIT;
  
  void rec_button::init(void) {
    LPC_GPIO1->DIR &= ~self::BIT;
    
    NVIC_EnableIRQ(EINT1_IRQn);
    LPC_GPIO1->IS  &= ~self::BIT;
    LPC_GPIO1->IBE &= ~self::BIT;
    LPC_GPIO1->IEV &= ~self::BIT;
    LPC_GPIO1->IE  |=  self::BIT;
  }
  
#else
  template<typename Callback>
  void rec_button::on_interrupt(Callback func) {
    if (!(LPC_GPIO1->MIS & self::BIT)) return;
    LPC_GPIO1->IC |= self::BIT;
    
    if (!(LPC_GPIO1->DATA & self::BIT)) func();
  }
#endif
}}
