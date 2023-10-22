
#include "interface_render_system.h"

namespace game::ecs {
    void InterfaceRenderSystem::render(
            core::context::RenderContext &ctx,
            Entities &entities, Field &field,
            const FieldRenderContext &fieldRenderCtx
    ) {
        if (const auto &player = entities.getEntity<Player>()) {
            auto &health = player.value()->health();
            auto &score = player.value()->score();

            _scoreText.setString("SCORE: " + std::to_string(score.get()));


            float freeSpace = ctx.window().getSize().x / 2 - fieldRenderCtx.getRenderSize().x / 2 - 64;

            _healthBar.setSize({freeSpace - 8, 24 - 8});
            _healthBarFill.setSize({
                                           freeSpace * health.ratio(),
                                           24
                                   });

            ctx.window().draw(_healthText);
            ctx.window().draw(_scoreText);

            ctx.window().draw(_healthBarFill);
            ctx.window().draw(_healthBar);

        }
    }

    void InterfaceRenderSystem::update(core::context::UpdateContext &ctx, Entities &entities, Field &field) {
    }

    void InterfaceRenderSystem::initialize(core::context::InitializeContext &ctx, Field &field) {
        _healthText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _healthText.setCharacterSize(32);

        _scoreText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _scoreText.setCharacterSize(32);

        _healthBar.setFillColor(sf::Color::Transparent);
        _healthBar.setOutlineColor(sf::Color(82, 0, 0));
        _healthBar.setOutlineThickness(4);
        _healthBarFill.setFillColor(sf::Color(158, 16, 37));

        _healthText.setPosition(16, 16);
        _healthBar.setPosition(16 + 4, 16 + 32 + 8 + 4);
        _healthBarFill.setPosition(16, 16 + 32 + 8);
        _scoreText.setPosition(16, 16 + 32 + 32);

        _healthText.setString("HEALTH");
        _scoreText.setString("SCORE");
    }
} // ecs