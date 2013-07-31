#include <crc/util.hpp>
#include <crc/application.hpp>
#include <crc/device/ir_xmtr.hpp>
#include <crc/device/rec_button.hpp>
#include <crc/device/clock.hpp>

extern "C" {
  void PIOINT1_IRQHandler(void) {
    crc::device::rec_button::on_interrupt([]{
      crc::util::singleton<crc::application>()->on_rec_button();
    });
  }
  
  void TIMER16_0_IRQHandler(void) {
    crc::device::clock::on_interrupt([]{
      crc::util::singleton<crc::application>()->on_clock();
    });
  }
  
  void TIMER32_1_IRQHandler(void) {
    crc::device::ir_xmtr::on_interrupt();
  }
}
