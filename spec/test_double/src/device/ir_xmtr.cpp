#include <crc/device/ir_xmtr.hpp>

namespace crc { namespace device {
  bool ir_xmtr::is_send_;
  
  void ir_xmtr::init(void) {
    ir_xmtr::is_send_ = false;
  }
  
  void ir_xmtr::send(void) {
    ir_xmtr::is_send_ = true;
  }
  
  void ir_xmtr::on_interrupt(void) {}
}}
