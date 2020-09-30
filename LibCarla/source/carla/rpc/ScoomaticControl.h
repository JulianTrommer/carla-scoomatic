#pragma once

#include "carla/MsgPack.h"

#ifdef LIBCARLA_INCLUDED_FROM_UE4
#  include "Carla/Scoomatic/ScoomaticControl.h"
#endif // LIBCARLA_INCLUDED_FROM_UE4

namespace carla {
namespace rpc {

  class ScoomaticControl {
  public:

    ScoomaticControl() = default;

    ScoomaticControl(
        float in_left_velocity,
        float in_right_velocity)
      : left_velocity(in_left_velocity),
        right_velocity(in_right_velocity) {}

    float left_velocity = 0.0f;
    float right_velocity = 0.0f;

#ifdef LIBCARLA_INCLUDED_FROM_UE4

    ScoomaticControl(const FScoomaticControl &Control)
      : left_velocity(Control.LeftVelocity),
        right_velocity(Control.RightVelocity) {}

    operator FScoomaticControl() const {
      FScoomaticControl Control;
      Control.LeftVelocity = left_velocity;
      Control.RightVelocity = right_velocity;
      return Control;
    }

#endif // LIBCARLA_INCLUDED_FROM_UE4

    bool operator!=(const ScoomaticControl &rhs) const {
      return
          left_velocity != rhs.left_velocity ||
          right_velocity != rhs.right_velocity;
    }

    bool operator==(const ScoomaticControl &rhs) const {
      return !(*this != rhs);
    }

    MSGPACK_DEFINE_ARRAY(left_velocity, right_velocity);
  };

} // namespace rpc
} // namespace carla
