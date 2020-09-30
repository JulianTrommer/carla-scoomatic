#pragma once

#include "carla/client/Actor.h"
#include "carla/rpc/ScoomaticControl.h"

namespace carla {
namespace client {

  class Scoomatic : public Actor {
  public:

    using Control = rpc::ScoomaticControl;

    explicit Scoomatic(ActorInitializer init);

    using ActorState::GetBoundingBox;

    /// Apply @a control to this scoomatic.
    void ApplyControl(const Control &control);

    /// Return the control last applied to this scoomatic.
    ///
    /// @note This function does not call the simulator, it returns the data
    /// received in the last tick.
    Control GetControl() const;

  private:

    const bool _is_control_sticky;

    Control _control;
  };

} // namespace client
} // namespace carla
