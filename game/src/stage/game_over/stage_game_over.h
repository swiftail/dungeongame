
#ifndef GAME_STAGE_GAME_OVER_H
#define GAME_STAGE_GAME_OVER_H

#include "game/src/stage/parametrized_stage.h"
#include "./game_over_data.h"

namespace game::stage::game_over {

    class StageGameOver : public ParametrizedStage<game_over::GameOverData> {
    private:
        sf::Text _mainText;
        sf::Text _detailsText;
        sf::Text _hintText;

        GameOverData _data;
    public:
        StageGameOver() = default;

        StageGameOver(StageGameOver const &) = delete;

        StageGameOver &operator=(StageGameOver const &) = delete;

        StageCode::Enum code() const override;

        void initialize(core::context::InitializeContext& ctx) override;

        void leave(core::context::InitializeContext& ctx) override;

        void enter(core::context::InitializeContext &ctx, const GameOverData &data) override;

        void update(core::context::UpdateContext &ctx) override;

        void render(core::context::RenderContext &ctx) override;
    };

} // stage

#endif //GAME_STAGE_GAME_OVER_H
