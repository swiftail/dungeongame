
#ifndef GAME_STAGE_VARIANT_H
#define GAME_STAGE_VARIANT_H

#include "game/src/stage/loading/stage_loading.h"
#include "game/src/stage/menu/stage_menu.h"
#include "game/src/stage/world/stage_world.h"
#include "game/src/stage/game_over/stage_game_over.h"
#include "game/src/util/type_util.h"

namespace game::stage::variant {
    using StageVariant = std::variant<
            std::reference_wrapper<loading::StageLoading>,
            std::reference_wrapper<menu::StageMenu>,
            std::reference_wrapper<world::StageWorld>,
            std::reference_wrapper<game_over::StageGameOver>
    >;

    StageVariant cast(Stage &stage);
}

#endif //GAME_STAGE_VARIANT_H
