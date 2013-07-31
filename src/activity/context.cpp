#include <crc/activity/context.hpp>
#include <crc/activity/base.hpp>

namespace crc { namespace activity {
  context::context(void) : current_activity(nullptr) {}
  
  void context::transition(activity::base * next, bool immediately) {
    if (this->current_activity != nullptr) this->current_activity->exit();
    this->current_activity = next;
    if (immediately) this->current_activity->entry(this);
  }
  
  void context::on_rec_button(void) {
    this->current_activity->on_rec_button();
    if (!this->current_activity->is_active()) this->current_activity->entry(this);
  }
  
  void context::on_clock(void) {
    this->current_activity->on_clock();
    if (!this->current_activity->is_active()) this->current_activity->entry(this);
  }
}}
