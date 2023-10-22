#include "has_position.h"

namespace game::ecs::entity::trait {

    HasPosition::HasPosition(const RestrictedVector<uint32_t> &position) :
            _position(position) {}

    RestrictedVector<uint32_t> &HasPosition::position() {
        return _position;
    }


}