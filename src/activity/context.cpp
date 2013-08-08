#include <crc/activity/context.hpp>
#include <crc/activity/base.hpp>

namespace crc { namespace activity {
  context::context(void) : current_activity_(nullptr) {}
  
  activity::base * context::current_activity(void) {
    return this->current_activity_;
  }
  
  void context::transition(activity::base * next, bool immediately) {
    if (this->current_activity_ != nullptr) this->current_activity_->exit();
    this->current_activity_ = next;
    if (immediately) this->current_activity_->entry(this);
  }
  
  void context::on_rec_button(void) {
    this->current_activity_->on_rec_button();
    if (!this->current_activity_->is_active()) this->current_activity_->entry(this);
  }
  
  void context::on_clock(void) {
    this->current_activity_->on_clock();
    if (!this->current_activity_->is_active()) this->current_activity_->entry(this);
  }
}}
