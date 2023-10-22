
#ifndef GAME_STAGE_WORLD_H
#define GAME_STAGE_WORLD_H

#include "../parametrized_stage.h"
#include "world_data.h"
#include <game/src/ecs/world.h>
#include <game/src/ecs/impl/action/factory/action_factory.h>

namespace game::stage::world {

    class StageWorld : public ParametrizedStage<WorldData> {
    private:
        sf::Sprite _backgroundSprite;

        std::unique_ptr<ecs::World> _world;
        std::unique_ptr<ecs::ActionFactory> _actionFactory;
        size_t _levelIndex;

    public:
        StageCode::Enum code() const override;

        void initialize(core::context::InitializeContext &ctx) override;

        void enter(core::context::InitializeContext &ctx, const WorldData &data) override;

        void leave(core::context::InitializeContext &ctx) override;

        void update(core::context::UpdateContext &ctx) override;

        void render(core::context::RenderContext &ctx) override;
    };

} // game

#endif //GAME_STAGE_WORLD_H
