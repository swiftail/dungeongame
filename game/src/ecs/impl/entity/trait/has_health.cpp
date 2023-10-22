#include "has_health.h"

namespace game::ecs::entity::trait {
    HasHealth::HasHealth(
            const int32_t_restrict &health
    ) : _health(health) {}

    int32_t_restrict &HasHealth::health() {
        return _health;
    }

    const tween::timeline::Timeline &HasHealth::damageTimeline() {
        return _damageTimeline;
    }

    void HasHealth::runDamageTimeline() {
        _damageTimeline.start();
    }

    void HasHealth::dealDamage(size_t amount) {
        _health.add(-amount);
        _damageTimeline.start();
    }
}