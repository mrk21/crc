#include <crc/device/clock.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
#ifndef __TEMPLATE_IMPLEMENTATION__
  constexpr uint32_t clock::IR_BIT;
  
  void clock::init(void) {
    LPC_IOCON->PIO0_8 |= (1<<1);
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<7);
    
    LPC_TMR16B0->PR = 36 - 1;
    LPC_TMR16B0->EMR |= (3<<4);
    LPC_TMR16B0->MCR |= (1<<6);
    NVIC_EnableIRQ(TIMER_16_0_IRQn);
    NVIC_SetPriority(TIMER_16_0_IRQn, 2);
  }
  
  void clock::start(void) {
    LPC_TMR16B0->TCR = 1;
  }
  
  void clock::stop(void) {
    LPC_TMR16B0->TCR = 0;
  }
  
#else
  template<typename Callback>
  void clock::on_interrupt(Callback callback) {
    if (!(LPC_TMR16B0->IR & self::IR_BIT)) return;
    LPC_TMR16B0->IR = self::IR_BIT;
    callback();
  }
#endif
}}
