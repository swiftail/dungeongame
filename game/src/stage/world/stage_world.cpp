
#include "stage_world.h"

#include <game/src/ecs/impl/entity/player.h>
#include <game/src/ecs/impl/system/interface_render_system.h>
#include <game/src/ecs/impl/system/movement_system.h>
#include <game/src/ecs/impl/system/field_render_system.h>
#include <game/src/ecs/impl/system/entity_render_system.h>
#include <game/src/ecs/impl/system/player_controls_system.h>
#include <game/src/ecs/impl/system/player_command_processing_system.h>
#include <game/src/ecs/impl/action/action_add_score.h>
#include "game/src/ser/mapper/level_mapper.h"
#include "game/src/ecs/level/levels.h"
#include "game/src/log/message/impl/level_failed_message.h"
#include "game/src/log/message/impl/level_completed_message.h"
#include "game/src/log/message/impl/level_started_message.h"
#include "game/src/ecs/impl/system/enemy_processing_system.h"
#include "game/src/ecs/entity/enemy/enemy.h"
#include "game/src/ecs/impl/entity/enemy/movement/path_movement_schema.h"
#include "game/src/ecs/impl/entity/enemy/interaction/deal_damage_interaction_schema.h"
#include "game/src/ecs/impl/entity/enemy/movement/smart_movement_schema.h"
#include "game/src/ecs/impl/entity/enemy/interaction/spawn_projectile_interaction_schema.h"

namespace game::stage::world {
    StageCode::Enum StageWorld::code() const {
        return StageCode::Enum::WORLD;
    }

    void StageWorld::initialize(core::context::InitializeContext &ctx) {
        _actionFactory = std::make_unique<ecs::ActionFactory>(ctx);

        _backgroundSprite.setTexture(ctx.resourceBundle().getResource(resource::ImageKey::BACKGROUND));
    }

    void StageWorld::enter(core::context::InitializeContext &ctx, const WorldData &data) {
        ctx.resourceBundle().getResource(resource::MusicKey::THEME).play();

        _levelIndex = data.levelIndex();
        _world = ser::mapper::LevelMapper::from(
                ctx,
                *_actionFactory,
                data.level()
        );

        ctx.logger().log(std::make_unique<log::message::impl::LevelStartedMessage>(
                _world->field().size(),
                _world->field().start()
        ));

        auto player = std::make_shared<ecs::Player>(_world->field().size(), _world->field().start());

        _world->entities().addEntity(player);

        std::shared_ptr<ecs::entity::Entity> entity = std::make_shared<
                ecs::entity::enemy::Enemy<
                        ecs::impl::entity::enemy::movement::SmartMovementSchema,
                        ecs::impl::entity::enemy::interaction::DealDamageInteractionSchema
                >
        >(
                std::make_unique<ecs::impl::entity::enemy::movement::SmartMovementSchema>(
                        *player
                ),
                std::make_unique<ecs::impl::entity::enemy::interaction::DealDamageInteractionSchema>(
                        std::make_unique<sf::Sound>(
                                ctx.resourceBundle().getResource(resource::SoundKey::HURT)
                        )
                        ),
                ecs::int32_t_restrict(100, 0, 100),
                _world->field().size(),
                _world->field().finish(),
                resource::texture::TextureKey::ENEMY_SKULL
        );

        _world->entities().addEntity(entity);


        std::shared_ptr<ecs::entity::Entity> entity2 = std::make_shared<
                ecs::entity::enemy::Enemy<
                        ecs::impl::entity::enemy::movement::PathMovementSchema,
                        ecs::impl::entity::enemy::interaction::SpawnProjectileInteractionSchema
                >
        >(
                std::make_unique<ecs::impl::entity::enemy::movement::PathMovementSchema>(
                        std::vector<sf::Vector2u>{sf::Vector2u{1,5}, sf::Vector2u {8, 5}}
                ),
                std::make_unique<ecs::impl::entity::enemy::interaction::SpawnProjectileInteractionSchema>(),
                ecs::int32_t_restrict(100, 0, 100),
                _world->field().size(),
                sf::Vector2u{5,5},
                resource::texture::TextureKey::ENEMY_ZOMBIE
        );

        _world->entities().addEntity(entity2);

        _world->addSystem(std::make_unique<ecs::InterfaceRenderSystem>());
        _world->addSystem(std::make_unique<ecs::PlayerControlsSystem>());
        _world->addSystem(std::make_unique<ecs::impl::system::PlayerCommandProcessingSystem>());
        _world->addSystem(std::make_unique<ecs::impl::system::EnemyProcessingSystem>());
        _world->addSystem(std::make_unique<ecs::MovementSystem>());
        _world->addSystem(std::make_unique<ecs::FieldRenderSystem>());
        _world->addSystem(std::make_unique<ecs::EntityRenderSystem>());

        _world->initialize(ctx);
    }

    void StageWorld::leave(core::context::InitializeContext &ctx) {
        ctx.resourceBundle().getResource(resource::MusicKey::THEME).stop();
    }

    void StageWorld::update(core::context::UpdateContext &ctx) {
        auto backgroundSize = ctx.resourceBundle().getResource(resource::ImageKey::BACKGROUND).getSize();
        auto windowSize = ctx.window().getSize();

        auto scaleFactor = std::max(
                (float) windowSize.x / (float) backgroundSize.x,
                (float) windowSize.y / (float) backgroundSize.y
        );

        _backgroundSprite.setScale(scaleFactor, scaleFactor);

        _world->update(ctx);

        if (const auto &player = _world->entities().getEntity<ecs::Player>()) {
            if (!player.value().get()->isAlive()) {
                ctx.logger().log(std::make_unique<log::message::impl::LevelFailedMessage>(
                        player.value().get()->score().get(),
                        player.value().get()->health().get(),
                        player.value().get()->position().get()
                ));
                ctx.switchStage<stage::StageCode::Enum::GAME_OVER>(std::make_unique<game_over::GameOverData>(
                        true,
                        player.value().get()->score().get(),
                        player.value().get()->health().get(),
                        _levelIndex
                ));
            }
            if (player.value().get()->position().get() == _world->field().finish()) {
                ctx.logger().log(std::make_unique<log::message::impl::LevelCompletedMessage>(
                        player.value().get()->score().get(),
                        player.value().get()->health().get()
                ));
                ctx.switchStage<stage::StageCode::Enum::GAME_OVER>(std::make_unique<game_over::GameOverData>(
                        false,
                        player.value().get()->score().get(),
                        player.value().get()->health().get(),
                        _levelIndex
                ));
            }
        }
    }

    void StageWorld::render(core::context::RenderContext &ctx) {
        ctx.window().clear(sf::Color::White);

        ctx.window().draw(_backgroundSprite);

        sf::RectangleShape dim;
        dim.setSize(ctx.window().getView().getSize());
        dim.setFillColor(sf::Color(0, 0, 0, 150));
        ctx.window().draw(dim);

        _world->render(ctx);
    }
} // game