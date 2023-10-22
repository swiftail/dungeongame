#ifndef GAME_STAGE_CODE_H
#define GAME_STAGE_CODE_H

#include "world/world_data.h"
#include "typeindex"

namespace game::stage {

    class StageCode {
    public:
        enum class Enum {
            LOADING,
            MENU,
            WORLD,
            GAME_OVER
        };
    };


}

#endif //GAME_STAGE_CODE_H
