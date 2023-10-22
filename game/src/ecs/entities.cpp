
#include "entities.h"

#include "game/src/ecs/impl/entity/trait/has_health.h"
#include "game/src/ecs/impl/entity/trait/has_position.h"
#include "game/src/ecs/impl/entity/trait/movable.h"
#include "game/src/ecs/impl/entity/trait/drawable.h"
#include "game/src/ecs/impl/entity/player.h"
#include "game/src/ecs/entity/enemy/base_enemy.h"

namespace game::ecs {
    const std::set<std::shared_ptr<entity::Entity>> &Entities::getEntities() {
        return _entities;
    }

    const std::set<std::type_index> &Entities::getAllKnownTypeIndexes(std::type_index index, std::shared_ptr<entity::Entity> entity) {
        if (!typeIndexCache.contains(index)) {
            std::set<std::type_index> result;

            CHECK_TYPE(entity::Entity);
            CHECK_TYPE(Player);
            CHECK_TYPE(entity::trait::Drawable);
            CHECK_TYPE(entity::trait::HasHealth);
            CHECK_TYPE(entity::trait::HasPosition);
            CHECK_TYPE(entity::trait::Movable);
            CHECK_TYPE(entity::enemy::BaseEnemy);

            typeIndexCache.insert({index, result});
        }

        return typeIndexCache.at(index);
    }
} // ecs