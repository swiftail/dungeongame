
#ifndef GAME_MOVEMENT_SYSTEM_H
#define GAME_MOVEMENT_SYSTEM_H

#include "../../system.h"
#include "../entity/trait/has_position.h"
#include "../entity/trait/movable.h"
#include "../entity/player.h"

namespace game::ecs {

    class MovementSystem : public System {

        void update(core::context::UpdateContext &ctx, Entities &entities, Field& field) override;;
    };

} // ecs

#endif //GAME_MOVEMENT_SYSTEM_H
