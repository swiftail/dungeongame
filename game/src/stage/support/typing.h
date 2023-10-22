
#ifndef GAME_TYPING_H
#define GAME_TYPING_H

#include "game/src/core/context/initialize_context.h"
#include "game/src/stage/stage_data.h"
#include "game/src/stage/stage_code.h"
#include "game/src/stage/loading/loading_data.h"
#include "game/src/stage/world/world_data.h"
#include "game/src/stage/menu/menu_data.h"
#include "game/src/stage/game_over/game_over_data.h"

namespace game::stage::support::typing {

    template<stage::StageCode::Enum e, class S>
    constexpr bool isValidDataType() {
        if constexpr (
                e == stage::StageCode::Enum::LOADING &&
                std::is_same_v<loading::LoadingData, S>
                ) {
            return true;
        }
        if constexpr (
                e == stage::StageCode::Enum::MENU &&
                std::is_same_v<menu::MenuData, S>
                ) {
            return true;
        }
        if constexpr (
                e == stage::StageCode::Enum::WORLD &&
                std::is_same_v<world::WorldData, S>
                ) {
            return true;
        }
        if constexpr (
                e == stage::StageCode::Enum::GAME_OVER &&
                std::is_same_v<game_over::GameOverData, S>
                ) {
            return true;
        }
        return false;
    }

} // stage

#endif //GAME_TYPING_H
