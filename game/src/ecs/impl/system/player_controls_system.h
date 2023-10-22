
#ifndef GAME_PLAYER_CONTROLS_SYSTEM_H
#define GAME_PLAYER_CONTROLS_SYSTEM_H

#include "../../system.h"
#include "../entity/player.h"

namespace game::ecs {

    class PlayerControlsSystem : public System {
        void update(core::context::UpdateContext &ctx, Entities &entities, Field &field) override;
    };

} // ecs

#endif //GAME_PLAYER_CONTROLS_SYSTEM_H
