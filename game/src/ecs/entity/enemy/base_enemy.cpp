
#include "base_enemy.h"

namespace game::ecs::entity::enemy {
    BaseEnemy::BaseEnemy(
            const int32_t_restrict &health,
            const RestrictedVector<uint32_t> &position,
            const sf::Vector2i &targetPosition
    ) : trait::HasHealth(health),
        trait::HasPosition(position),
        trait::Movable(targetPosition) {}
} // enemy