
#ifndef GAME_DEAL_DAMAGE_INTERACTION_SCHEMA_H
#define GAME_DEAL_DAMAGE_INTERACTION_SCHEMA_H

#include "game/src/ecs/entity/enemy/base_enemy.h"
#include "game/src/ecs/impl/entity/player.h"
#include "SFML/Audio/Sound.hpp"
#include "game/src/core/context/update_context.h"

namespace game::ecs::impl::entity::enemy::interaction {

    class DealDamageInteractionSchema {
    private:
        std::unique_ptr<sf::Sound> _sound;

    public:
        DealDamageInteractionSchema(DealDamageInteractionSchema const &) = delete;

        DealDamageInteractionSchema() = delete;

        DealDamageInteractionSchema &operator=(DealDamageInteractionSchema const &) = delete;

        DealDamageInteractionSchema(
                std::unique_ptr<sf::Sound> sound
        );

        bool _interact(
                game::core::context::UpdateContext &ctx,
                game::ecs::entity::enemy::BaseEnemy &self,
                Entities &entities,
                Field &field
        );
    };

} // interaction

#endif //GAME_DEAL_DAMAGE_INTERACTION_SCHEMA_H
