
#include "spawn_projectile_interaction_schema.h"
#include "game/src/ecs/entity/enemy/enemy.h"
#include "game/src/ecs/impl/entity/enemy/movement/direction_movement_schema.h"
#include "deal_damage_interaction_schema.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::entity::enemy::interaction {
    bool SpawnProjectileInteractionSchema::_interact(
            game::core::context::UpdateContext &ctx,
            game::ecs::entity::enemy::BaseEnemy &self,
            Entities &entities,
            Field &field
    ) {
        if (const auto &player = entities.getEntity<Player>()) {
            const auto &selfPosition = self.position().get();
            const auto &playerPosition = player.value()->position().get();
            if (selfPosition.x == playerPosition.x || selfPosition.y == playerPosition.y) {
                sf::Vector2i direction = {
                        -game::util::math::sgn((int32_t) selfPosition.x - (int32_t) playerPosition.x),
                        -game::util::math::sgn((int32_t) selfPosition.y - (int32_t) playerPosition.y),
                };

                if (direction == sf::Vector2i{0, 0}) {
                    direction.x = 1;
                }

                std::shared_ptr<ecs::entity::Entity> projectile = std::make_shared<
                        ecs::entity::enemy::Enemy<
                                ecs::impl::entity::enemy::movement::DirectionMovementSchema,
                                ecs::impl::entity::enemy::interaction::DealDamageInteractionSchema
                        >
                >(
                        std::make_unique<ecs::impl::entity::enemy::movement::DirectionMovementSchema>(
                                direction
                        ),
                        std::make_unique<ecs::impl::entity::enemy::interaction::DealDamageInteractionSchema>(
                                std::make_unique<sf::Sound>(
                                        ctx.resourceBundle().getResource(resource::SoundKey::HURT)
                                )
                        ),
                        ecs::int32_t_restrict(1, 0, 1),
                        field.size(),
                        self.position().get(),
                        resource::texture::TextureKey::ENEMY_PROJECTILE
                );

                entities.addEntity(projectile);
                return true;
            }
        }

        return false;
    }
} // interaction