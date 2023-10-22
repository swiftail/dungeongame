
#ifndef GAME_DIRECTION_MOVEMENT_SCHEMA_H
#define GAME_DIRECTION_MOVEMENT_SCHEMA_H

#include "SFML/System/Vector2.hpp"
#include "game/src/ecs/field/field.h"

namespace game::ecs::impl::entity::enemy::movement {

    class DirectionMovementSchema {
    private:
        sf::Vector2i _direction;
    public:
        DirectionMovementSchema(const sf::Vector2i &direction);

        sf::Vector2i _move(const Field &field, const sf::Vector2u &currentPosition);
    };

} // movement

#endif //GAME_DIRECTION_MOVEMENT_SCHEMA_H
