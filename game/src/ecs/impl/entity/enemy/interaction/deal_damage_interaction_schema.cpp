
#include "deal_damage_interaction_schema.h"

#include "iostream"

namespace game::ecs::impl::entity::enemy::interaction {
    bool DealDamageInteractionSchema::_interact(
            game::core::context::UpdateContext& ctx,
            game::ecs::entity::enemy::BaseEnemy &self,
            Entities &entities,
            Field& field
            ) {
        if (const auto &player = entities.getEntity<Player>()) {
            if (self.position().get() == player.value()->position().get()) {
                _sound->play();
                player.value()->dealDamage(1);
                return true;
            }
        }

        return false;
    }

    DealDamageInteractionSchema::DealDamageInteractionSchema(std::unique_ptr<sf::Sound> sound)
            : _sound(std::move(sound)) {

    }
} // interaction