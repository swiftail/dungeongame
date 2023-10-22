
#ifndef GAME_ENEMY_PROCESSING_SYSTEM_H
#define GAME_ENEMY_PROCESSING_SYSTEM_H

#include "../../system.h"

namespace game::ecs::impl::system {

    class EnemyProcessingSystem : public System {
    private:
        game::tween::timeline::Timeline _timer{sf::seconds(0.5f)};
        std::map<size_t, tween::timeline::Timeline> _interactionTimers;

    public:
        EnemyProcessingSystem() {
            _timer.start();
        }

        void update(core::context::UpdateContext &ctx, Entities &entities, Field &field) override;
    };

} // system

#endif //GAME_ENEMY_PROCESSING_SYSTEM_H
