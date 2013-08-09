#include <crc/device/uart.hpp>
#include <LPC11xx.h>

namespace crc { namespace device {
  void uart::init(void) {
    LPC_IOCON->PIO1_6 |= 0x01;
    LPC_IOCON->PIO1_7 |= 0x01;
    LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12);
    LPC_SYSCON->UARTCLKDIV = 0x01;
    
    auto DL = (SystemCoreClock * LPC_SYSCON->SYSAHBCLKDIV) / (16 * BAUDRATE * LPC_SYSCON->UARTCLKDIV);
    LPC_UART->LCR |= (1<<7);
    LPC_UART->DLM = DL / 256;
    LPC_UART->DLL = DL % 256;
    LPC_UART->LCR &= ~(1<<7);
    LPC_UART->LCR = 0x03;
    LPC_UART->FCR = 0x07;
  }
  
  void uart::write(char data) {
    while (!(LPC_UART->LSR &  (1<<5)));
    LPC_UART->THR = data;
  }
}}
