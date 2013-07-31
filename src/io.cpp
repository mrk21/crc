#include <crc/io.hpp>
#include <crc/device/uart.hpp>

namespace crc {
  void io::write(char data) {
    device::uart::write(data);
  }
  
  void io::write(uint32_t data) {
    static char stack[10];
    uint8_t p = 0;
    
    do {
      stack[p++] = '0' + (data % 10);
    } while ((data /= 10) != 0);
    
    for (int i=p-1; i>=0; --i) write(stack[i]);
  }
  
  void io::write(const char * data) {
    while (*data != '\0') write(*data++);
  }
}
