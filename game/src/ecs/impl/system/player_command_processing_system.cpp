
#include "player_command_processing_system.h"
#include "game/src/ecs/impl/entity/player.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::system {
    void PlayerCommandProcessingSystem::update(core::context::UpdateContext &ctx, Entities &entities, Field &field) {
        if (const auto &player = entities.getEntity<Player>()) {
            if (player.value().get()->command() != MoveDirection::Enum::null) {
                auto direction = player.value().get()->command();

                const auto &position = player.value()->position().get();
                const auto &unitVector = MoveDirection::unitVector(direction);
                sf::Vector2i newPosition = {
                        (int32_t) position.x + unitVector.x,
                        (int32_t) position.y + unitVector.y,
                };

                // copy
                RestrictedVector<uint32_t> newPositionRestricted = player.value()->position();
                newPositionRestricted.set(newPosition);

                player.value()->setTargetPosition(game::util::math::transform<int>(newPositionRestricted.get()));
                player.value().get()->setCommand(MoveDirection::Enum::null);
            }
        }
    }
} // system