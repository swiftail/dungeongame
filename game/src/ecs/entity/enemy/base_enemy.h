
#ifndef GAME_BASE_ENEMY_H
#define GAME_BASE_ENEMY_H

#include "game/src/ecs/entity/entity.h"
#include "game/src/ecs/impl/entity/trait/has_position.h"
#include "game/src/ecs/impl/entity/trait/has_health.h"
#include "game/src/ecs/impl/entity/trait/movable.h"
#include "game/src/ecs/impl/entity/trait/drawable.h"
#include "game/src/ecs/field/field.h"
#include "game/src/ecs/impl/entity/player.h"
#include "game/src/ecs/entities.h"
#include "game/src/core/context/update_context.h"

namespace game::ecs::entity::enemy {

    class BaseEnemy :
            public trait::HasHealth,
            public trait::HasPosition,
            public trait::Movable,
            public trait::Drawable {
    public:
        BaseEnemy(
                const int32_t_restrict &health,
                const RestrictedVector<uint32_t> &position,
                const sf::Vector2i &targetPosition
        );

        virtual void move(const Field &field) = 0;

        virtual bool interact(
                game::core::context::UpdateContext &ctx,
                game::ecs::Entities &entities,
                game::ecs::Field &field
        ) = 0;
    };

} // enemy

#endif //GAME_BASE_ENEMY_H
