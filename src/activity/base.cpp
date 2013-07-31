#include <crc/activity/base.hpp>

namespace crc { namespace activity {
  base::base(void) : context(nullptr), is_active_(false) {}
  
  bool base::is_active(void) {
    return this->is_active_;
  }
  
  void base::entry(activity::context * context) {
    this->context = context;
    this->is_active_ = true;
    this->start();
  }
  
  void base::exit() {
    this->stop();
    this->is_active_ = false;
    this->context = nullptr;
  }
  
  void base::start(void) {}
  void base::stop(void) {}
  void base::on_rec_button(void) {}
  void base::on_clock(void) {}
}}
