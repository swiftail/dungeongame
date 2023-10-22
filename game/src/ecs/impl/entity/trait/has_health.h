
#ifndef GAME_HAS_HEALTH_H
#define GAME_HAS_HEALTH_H

#include "game/src/ecs/entity/entity.h"
#include "game/src/ecs/impl/data/int32_t_restrict.h"
#include "game/src/tween/timeline/timeline.h"

namespace game::ecs::entity::trait {
    class HasHealth {
    protected:
        int32_t_restrict _health;
        tween::timeline::Timeline _damageTimeline = tween::timeline::Timeline(sf::seconds(0.5));

    public:
        HasHealth(const int32_t_restrict &health);

        HasHealth(HasHealth const &) = delete;

        HasHealth &operator=(HasHealth const &) = delete;

        int32_t_restrict &health();

        const tween::timeline::Timeline &damageTimeline();

        void runDamageTimeline();

        void dealDamage(size_t amount);
    };
}

#endif //GAME_HAS_HEALTH_H
