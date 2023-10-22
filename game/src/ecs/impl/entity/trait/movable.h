
#ifndef GAME_MOVABLE_H
#define GAME_MOVABLE_H

#include "../../data/move_direction.h"
#include "game/src/ecs/entity/entity.h"

namespace game::ecs::entity::trait {

    class Movable {
    protected:
        sf::Vector2i _targetPosition;
    public:
        Movable(const sf::Vector2i& targetPosition);

        Movable(Movable const &) = delete;

        Movable &operator=(Movable const &) = delete;

        const sf::Vector2i &targetPosition();

        void setTargetPosition(const sf::Vector2i &position);
    };

} // trait

#endif //GAME_MOVABLE_H
