
#ifndef GAME_STAGE_REGISTRY_H
#define GAME_STAGE_REGISTRY_H

#include <map>
#include "stage.h"
#include "parametrized_stage.h"

#include <any>

namespace game::stage {
    class StageRegistry {
    private:
        std::map<StageCode::Enum, std::unique_ptr<Stage>> _data;


    public:
        StageRegistry(StageRegistry&&) = default;

        StageRegistry(StageRegistry const &) = delete;

        StageRegistry() = delete;

        StageRegistry &operator=(StageRegistry const &) = delete;

        explicit StageRegistry(std::vector<std::unique_ptr<Stage>> &stages);

        Stage &getStage(StageCode::Enum code) const;

        void initializeAll(core::context::InitializeContext& ctx) const;

    };
} // game

#endif //GAME_STAGE_REGISTRY_H
