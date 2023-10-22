
#include "entity_render_system.h"

#include "game/src/resource/texture/texture_registry.h"
#include "game/src/graphics/sprite/sprite_render_util.h"

namespace game::ecs {
    void EntityRenderSystem::render(
            core::context::RenderContext &ctx,
            Entities &entities,
            Field &field,
            const FieldRenderContext &fieldRenderCtx
    ) {
        for (const auto &drawable: entities.getEntities<entity::trait::Drawable>()) {
            auto hasPosition = util::cast<entity::trait::HasPosition>(drawable.get());
            auto hasHealth = util::cast<entity::trait::HasHealth>(drawable.get());
            auto entity = util::cast<entity::Entity>(drawable.get());

            if (!entity->isAlive()) {
                continue;
            }

            if (!drawable || !hasPosition) {
                continue;
            }

            sf::Sprite sprite;
            resource::texture::TextureRegistry::instance()
                    .get(drawable->textureKey())
                    ->applyToSprite(ctx.resourceBundle(), sprite);

            const auto &coords = hasPosition->position().get();

            if (hasHealth) {
                const auto &damageTimeline = hasHealth->damageTimeline();

                if (damageTimeline.isStarted()) {
                    auto tintColor = tween::Tween::apply(
                            damageTimeline,
                            _damageColorMapping
                    );

                    sprite.setColor(tintColor);
                }
            }

            sprite.setScale(fieldRenderCtx.getCellSpriteScale(sprite.getTextureRect()));
            sprite.setPosition(
                    fieldRenderCtx.getCellRenderPositionCentered(
                            {(uint32_t) coords.x, (uint32_t) coords.y}));
            game::graphics::sprite::SpriteRenderUtil::centerOrigin(sprite);

            ctx.window().draw(sprite);

        }
    }

} // ecs