
#include "action_factory.h"

namespace game {
    namespace ecs {
        ActionFactory::ActionFactory(const core::context::InitializeContext &ctx) :
                _actionAddScore(std::make_shared<ActionAddScore>(
                        std::make_unique<sf::Sound>(
                                ctx.resourceBundle().getResource(resource::SoundKey::PICKUP)
                        )
                )),
                _actionSpike(std::make_shared<impl::action::ActionSpike>(
                        std::make_unique<sf::Sound>(
                                ctx.resourceBundle().getResource(resource::SoundKey::HURT)
                        )
                )) {}

        std::shared_ptr<ActionAddScore> ActionFactory::addScore() const {
            return _actionAddScore;
        }

        std::shared_ptr<impl::action::ActionSpike> ActionFactory::spike() const {
            return _actionSpike;
        }

        std::shared_ptr<impl::action::ActionPortal>
        ActionFactory::portal(const core::context::InitializeContext &ctx, const sf::Vector2u &target) const {
            return std::make_shared<impl::action::ActionPortal>(
                    std::make_unique<sf::Sound>(
                            ctx.resourceBundle().getResource(resource::SoundKey::TELEPORT)
                    ),
                    target
            );
        }
    } // game
} // ecs