
#include "stage_variant.h"

namespace game::stage::variant {
    StageVariant cast(game::stage::Stage &stage) {
        if (util::cast<loading::StageLoading>(&stage)) {
            return std::reference_wrapper<loading::StageLoading>(dynamic_cast<loading::StageLoading &>(stage));
        }
        if (util::cast<menu::StageMenu>(&stage)) {
            return std::reference_wrapper<menu::StageMenu>(dynamic_cast<menu::StageMenu &>(stage));
        }
        if (util::cast<world::StageWorld>(&stage)) {
            return std::reference_wrapper<world::StageWorld>(dynamic_cast<world::StageWorld &>(stage));
        }
        if (util::cast<game_over::StageGameOver>(&stage)) {
            return std::reference_wrapper<game_over::StageGameOver>(dynamic_cast<game_over::StageGameOver &>(stage));
        }
        throw std::logic_error("No way!");
    }
}
