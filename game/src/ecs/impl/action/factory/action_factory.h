
#ifndef GAME_ACTION_FACTORY_H
#define GAME_ACTION_FACTORY_H

#include <utility>
#include "../action_add_score.h"
#include "../action_spike.h"
#include "../action_portal.h"
#include "../../../../core/context/initialize_context.h"

namespace game::ecs {
    class ActionFactory {
    private:
        std::shared_ptr<ActionAddScore> _actionAddScore;
        std::shared_ptr<impl::action::ActionSpike> _actionSpike;

    public:
        ActionFactory(ActionFactory const &) = delete;

        ActionFactory() = delete;

        ActionFactory &operator=(ActionFactory const &) = delete;

        ActionFactory(
                const core::context::InitializeContext &ctx
        );

        std::shared_ptr<ActionAddScore> addScore() const;;

        std::shared_ptr<impl::action::ActionSpike> spike() const;;

        std::shared_ptr<impl::action::ActionPortal> portal(
                const core::context::InitializeContext &ctx,
                const sf::Vector2u &target
        ) const;;

    };

} // ecs

#endif //GAME_ACTION_FACTORY_H
