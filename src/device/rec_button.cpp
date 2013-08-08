#include <crc/device/rec_button.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
#ifndef __TEMPLATE_IMPLEMENTATION__
  void rec_button::init(void) {
    LPC_GPIO1->DIR &= ~(1<<8);
    
    NVIC_EnableIRQ(EINT1_IRQn);
    LPC_GPIO1->IS  &= ~(1<<8);
    LPC_GPIO1->IBE &= ~(1<<8);
    LPC_GPIO1->IEV &= ~(1<<8);
    LPC_GPIO1->IE  |=  (1<<8);
  }
  
#else
  template<typename Callback>
  void rec_button::on_interrupt(Callback func) {
    if (!(LPC_GPIO1->MIS & (1<<8))) return;
    LPC_GPIO1->IC |= (1<<8);
    
    if (!(LPC_GPIO1->DATA & (1<<8))) func();
  }
#endif
}}
