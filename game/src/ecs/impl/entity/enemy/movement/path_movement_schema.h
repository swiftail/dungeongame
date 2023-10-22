
#ifndef GAME_PATH_MOVEMENT_SCHEMA_H
#define GAME_PATH_MOVEMENT_SCHEMA_H

#include <vector>
#include "SFML/System/Vector2.hpp"
#include "game/src/ecs/field/field.h"

namespace game::ecs::impl::entity::enemy::movement {

    class PathMovementSchema {
    private:
        std::vector<sf::Vector2u> _path;
        uint32_t _index = 0;
    public:
        PathMovementSchema(const std::vector<sf::Vector2u> &path);

        sf::Vector2i _move(const Field& field, const sf::Vector2u &currentPosition);
    };

} // move_schema

#endif //GAME_PATH_MOVEMENT_SCHEMA_H
