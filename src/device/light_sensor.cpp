#include <crc/device/light_sensor.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
  void light_sensor::init(void) {
    LPC_IOCON->R_PIO1_0 &= ~(1<<7);
    LPC_IOCON->R_PIO1_0 &= ~(1<<4);
    LPC_IOCON->R_PIO1_0 |= (1<<1);
    LPC_SYSCON->PDRUNCFG &= ~(1<<4);
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);
    LPC_ADC->CR |= (1<<1);
    LPC_ADC->CR |= (10<<8);
    LPC_ADC->CR |= (1<<16);
  }
  
  uint32_t light_sensor::get(void) {
    uint32_t data;
    while (((data = LPC_ADC->DR[1]) & (1<<31)) == 0);
    return (data >> 6) & 0x3ff;
  }
}}
