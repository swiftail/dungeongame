
#ifndef GAME_PLAYER_COMMAND_PROCESSING_SYSTEM_H
#define GAME_PLAYER_COMMAND_PROCESSING_SYSTEM_H

#include "../../system.h"
#include "game/src/ecs/system.h"

namespace game::ecs::impl::system {

    class PlayerCommandProcessingSystem : public System {
        void update(core::context::UpdateContext &ctx, Entities &entities, Field &field) override;
    };

} // system

#endif //GAME_PLAYER_COMMAND_PROCESSING_SYSTEM_H
