
#ifndef GAME_ACTION_PORTAL_H
#define GAME_ACTION_PORTAL_H

#include "../../field/cell/action/cell_action.h"
#include "../entity/player.h"
#include "SFML/Audio/Sound.hpp"

namespace game::ecs::impl::action {

    class ActionPortal : public CellAction {
    private:
        sf::Vector2u _targetPosition;
        std::unique_ptr<sf::Sound> _sound;

//        static tween::timeline::Timeline &throttle() {
//            static tween::timeline::Timeline instance = sf::seconds(0.5);
//            return instance;
//        }

    public:
        ActionPortal(ActionPortal const &) = delete;

        ActionPortal() = delete;

        ActionPortal &operator=(ActionPortal const &) = delete;

        ActionPortal(
                std::unique_ptr<sf::Sound> sound,
                const sf::Vector2u &_targetPosition
        );

        resource::texture::TextureKey textureKey() const override;

        ActionResult activate(entity::Entity &entity) const override;

        bool isObstacle() const override;
    };

} // action

#endif //GAME_ACTION_PORTAL_H
