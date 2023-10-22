
#include "stage_registry.h"
#include "game/src/stage/loading/stage_loading.h"
#include "game/src/stage/menu/stage_menu.h"
#include "game/src/stage/world/stage_world.h"
#include "stage_data.h"

namespace game::stage {
    StageRegistry::StageRegistry(std::vector<std::unique_ptr<Stage>> &stages) {
        for (auto &item: stages) {
            _data.insert(std::make_pair<StageCode::Enum, std::unique_ptr<Stage>>(item->code(), std::move(item)));
        }
    }

    Stage &StageRegistry::getStage(StageCode::Enum code) const {
        return *_data.at(code);
    }


}