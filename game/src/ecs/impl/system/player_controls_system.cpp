
#include "player_controls_system.h"

#include "game/src/log/message/impl/key_not_processed_message.h"
#include "game/src/log/message/impl/key_processed_message.h"

namespace game::ecs {
    void PlayerControlsSystem::update(core::context::UpdateContext &ctx, Entities &entities, Field &field) {
        if (const auto &player = entities.getEntity<Player>()) {
            for (const auto &event: ctx.events()) {
                if (event.type == sf::Event::KeyPressed) {
                    auto key = event.key.code;

                    if (ctx.keyConfig().mapping().contains(key)) {
                        auto command = ctx.keyConfig().mapping().at(key);
                        player.value().get()->setCommand(command);
                        ctx.logger().log(std::make_unique<log::message::impl::KeyProcessedMessage>(
                                key,
                                command
                        ));
                    } else {
                        ctx.logger().log(std::make_unique<log::message::impl::KeyNotProcessedMessage>(
                                key
                        ));
                    }
                }
            }
        }
    }
} // ecs