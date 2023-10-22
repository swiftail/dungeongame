
#ifndef GAME_ACTION_ADD_SCORE_H
#define GAME_ACTION_ADD_SCORE_H

#include "../../field/cell/action/cell_action.h"
#include "../entity/player.h"
#include "SFML/Audio/Sound.hpp"

#include <iostream>

namespace game::ecs {

    class ActionAddScore : public CellAction {
    private:
        std::unique_ptr<sf::Sound> _sound;

    public:
        ActionAddScore(ActionAddScore const &) = delete;

        ActionAddScore() = delete;

        ActionAddScore &operator=(ActionAddScore const &) = delete;

        ActionAddScore(
                std::unique_ptr<sf::Sound> sound
        );

        resource::texture::TextureKey textureKey() const override;

        ActionResult activate(entity::Entity &entity) const override;

        bool isObstacle() const override;
    };

} // ecs

#endif //GAME_ACTION_ADD_SCORE_H
