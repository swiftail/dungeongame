
#include "enemy_processing_system.h"

#include "game/src/ecs/entity/enemy/base_enemy.h"

namespace game::ecs::impl::system {
    void EnemyProcessingSystem::update(core::context::UpdateContext &ctx, Entities &entities, Field &field) {
        bool shouldMove = _timer.isEnded();
        if (shouldMove) {
            _timer.start();
        }

        for (const auto &item: entities.getEntities<entity::enemy::BaseEnemy>()) {
            const auto entity = util::cast<entity::Entity>(item.get());

            if (!entity->isAlive()) {
                continue;
            }

            if (shouldMove) {
                item->move(field);
            }

            bool shouldInteract = true;
            if (_interactionTimers.contains(entity->id())) {
                const auto &interactionTimer = _interactionTimers.at(entity->id());

                if (!interactionTimer.isEnded()) {
                    shouldInteract = false;
                }
            }

            if (shouldInteract) {
                bool interactionSuccess = item->interact(ctx, entities, field);

                if (interactionSuccess) {
                    _interactionTimers.insert_or_assign(entity->id(), game::tween::timeline::Timeline{sf::seconds(0.25f)}.start());
                }
            }
        }
    }
} // system