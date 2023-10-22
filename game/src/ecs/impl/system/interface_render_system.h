
#ifndef GAME_INTERFACE_RENDER_SYSTEM_H
#define GAME_INTERFACE_RENDER_SYSTEM_H

#include "../../system.h"
#include "../entity/player.h"
#include "../../../graphics/text/text_render_util.h"
#include <iostream>

namespace game::ecs {

    class InterfaceRenderSystem : public System {
    private:
        sf::Text _healthText;
        sf::Text _scoreText;
        sf::RectangleShape _healthBar;
        sf::RectangleShape _healthBarFill;

    public:

        void initialize(core::context::InitializeContext &ctx, Field& field) override;

        void update(core::context::UpdateContext &ctx, Entities &entities, Field& field) override;

        void render(core::context::RenderContext &ctx, Entities &entities, Field& field, const FieldRenderContext& fieldRenderCtx) override;

    };

} // ecs

#endif //GAME_INTERFACE_RENDER_SYSTEM_H
