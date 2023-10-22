
#include "field_render_system.h"

#include "game/src/graphics/sprite/sprite_render_util.h"

namespace game::ecs {
    void FieldRenderSystem::render(
            core::context::RenderContext &ctx,
            Entities &entities,
            Field &field,
            const FieldRenderContext &fieldRenderCtx
    ) {
        const auto &size = field.size();

        for (uint32_t x = 0; x < size.x; x++) {
            for (uint32_t y = 0; y < size.y; y++) {
                auto coords = sf::Vector2u(x, y);
                const auto &cell = field.getCell(coords);
                auto renderPosition = fieldRenderCtx.getCellRenderPositionCentered(coords);

                sf::Sprite sprite;
                resource::texture::TextureRegistry::instance()
                        .get(cell.textureKey())
                        ->applyToSprite(ctx.resourceBundle(), sprite);

                graphics::sprite::SpriteRenderUtil::centerOrigin(sprite);
                sprite.setScale(fieldRenderCtx.getCellSpriteScale(sprite.getTextureRect()));
                sprite.setPosition(renderPosition);

                ctx.window().draw(sprite);

                if (field.start() == coords) {
                    sf::Sprite startSprite;
                    resource::texture::TextureRegistry::instance()
                            .get(resource::texture::TextureKey::CELL_TRAPDOOR)
                            ->applyToSprite(ctx.resourceBundle(), startSprite);

                    graphics::sprite::SpriteRenderUtil::centerOrigin(startSprite);
                    startSprite.setScale(fieldRenderCtx.getCellSpriteScale(startSprite.getTextureRect()));
                    startSprite.setPosition(renderPosition);

                    ctx.window().draw(startSprite);
                }
                if (field.finish() == coords) {
                    sf::Sprite finishSprite;
                    resource::texture::TextureRegistry::instance()
                            .get(resource::texture::TextureKey::CELL_LADDER)
                            ->applyToSprite(ctx.resourceBundle(), finishSprite);

                    graphics::sprite::SpriteRenderUtil::centerOrigin(finishSprite);
                    finishSprite.setScale(fieldRenderCtx.getCellSpriteScale(finishSprite.getTextureRect()));
                    finishSprite.setPosition(renderPosition);

                    ctx.window().draw(finishSprite);
                }

                if (const auto &action = cell.action()) {
                    sf::Sprite actionSprite;

                    actionSprite.setPosition(renderPosition);

                    resource::texture::TextureRegistry::instance()
                            .get(action.value().get().textureKey())
                            ->applyToSprite(ctx.resourceBundle(), actionSprite);

                    graphics::sprite::SpriteRenderUtil::centerOrigin(actionSprite);
                    actionSprite.setScale(fieldRenderCtx.getCellSpriteScale(actionSprite.getTextureRect()));

                    ctx.window().draw(actionSprite);
                }
            }
        }
    }

} // ecs