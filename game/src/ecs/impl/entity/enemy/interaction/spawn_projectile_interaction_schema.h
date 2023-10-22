
#ifndef GAME_SPAWN_PROJECTILE_INTERACTION_SCHEMA_H
#define GAME_SPAWN_PROJECTILE_INTERACTION_SCHEMA_H

#include "game/src/ecs/entities.h"
#include "game/src/ecs/field/field.h"
#include "game/src/ecs/entity/enemy/base_enemy.h"
#include "game/src/core/context/update_context.h"

namespace game::ecs::impl::entity::enemy::interaction {

    class SpawnProjectileInteractionSchema {
    public:
        bool _interact(
                game::core::context::UpdateContext &ctx,
                game::ecs::entity::enemy::BaseEnemy &self,
                Entities &entities,
                Field &field
        );
    };

} // interaction

#endif //GAME_SPAWN_PROJECTILE_INTERACTION_SCHEMA_H
