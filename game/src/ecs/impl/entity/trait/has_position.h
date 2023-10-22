
#ifndef GAME_HAS_POSITION_H
#define GAME_HAS_POSITION_H

#include "../../data/restricted_vector.h"
#include "game/src/ecs/entity/entity.h"

namespace game::ecs::entity::trait {
    class HasPosition {
    protected:
        RestrictedVector<uint32_t> _position;
    public:
        HasPosition(const RestrictedVector<uint32_t>& position);

        HasPosition(HasPosition const &) = delete;

        HasPosition &operator=(HasPosition const &) = delete;

        RestrictedVector<uint32_t> &position();
    };
} // ecs

#endif //GAME_HAS_POSITION_H
