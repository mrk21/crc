#include <crc/device/ir_xmtr.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
  constexpr uint32_t ir_xmtr::IR_BIT;
  constexpr uint32_t ir_xmtr::EMR_BIT;
  
  
  constexpr uint8_t ir_xmtr::SIGNAL[];
  uint32_t ir_xmtr::irq_count = 0;
  uint32_t ir_xmtr::signal_count = 0;
  
  void ir_xmtr::init(void) {
    NVIC_EnableIRQ(TIMER_32_1_IRQn);
    NVIC_SetPriority(TIMER_32_1_IRQn, 1);
    
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<10);
    LPC_IOCON->R_PIO1_1 |= 0b11;
    
    LPC_TMR32B1->PR = 2400/38 - 1;
    LPC_TMR32B1->MCR  |= (1<<7);
    LPC_TMR32B1->MR2 = 10 - 1;
  }
  
  void ir_xmtr::send(void) {
    self::irq_count = 0;
    self::signal_count = 0;
    self::off();
    
    LPC_TMR32B1->MCR |= self::IR_BIT;
    LPC_TMR32B1->TCR = 1;
  }
  
  void ir_xmtr::on_interrupt(void) {
    if (!(LPC_TMR32B1->IR & self::IR_BIT)) return;
    LPC_TMR32B1->IR = self::IR_BIT;
    
    if (self::irq_count == 0) {
      if (self::signal_count >= self::SIGNAL_SIZE) {
        self::stop();
        return;
      }
      self::SIGNAL[self::signal_count++] ? self::on() : self::off();
    }
    self::irq_count = (self::irq_count + 1) % self::TRANSMIT_SIZE;
  }
  
  void ir_xmtr::stop(void) {
    self::off();
    LPC_TMR32B1->MCR &= ~self::IR_BIT;
    LPC_TMR32B1->TCR = 0;
  }
  
  void ir_xmtr::on(void) {
    LPC_TMR32B1->EMR |= 0b11 * self::EMR_BIT;
  }
  
  void ir_xmtr::off(void) {
    LPC_TMR32B1->EMR &= ~(0b11 * self::EMR_BIT);
    LPC_TMR32B1->EMR |= self::EMR_BIT;
  }
}}
