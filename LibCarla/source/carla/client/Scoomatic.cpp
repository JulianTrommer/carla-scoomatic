#include "carla/client/Scoomatic.h"

#include "carla/client/detail/Simulator.h"
#include "carla/client/ActorList.h"

namespace carla {
namespace client {

  template <typename AttributesT>
  static bool GetControlIsSticky(const AttributesT &attributes) {
    for (auto &&attribute : attributes) {
      if (attribute.GetId() == "sticky_control") {
        return attribute.template As<bool>();
      }
    }
    return true;
  }

  Scoomatic::Scoomatic(ActorInitializer init)
    : Actor(std::move(init)),
      _is_control_sticky(GetControlIsSticky(GetAttributes())) {}

  void Scoomatic::ApplyControl(const Control &control) {
    if (control != _control) {
      GetEpisode().Lock()->ApplyControlToScoomatic(*this, control);
      _control = control;
    }
  }

  Scoomatic::Control Scoomatic::GetControl() const {
    return GetEpisode().Lock()->GetActorSnapshot(*this).state.scoomatic_control;
  }

} // namespace client
} // namespace carla
