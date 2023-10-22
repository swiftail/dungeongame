
#ifndef GAME_SEARCH_H
#define GAME_SEARCH_H

#include "SFML/System/Vector2.hpp"
#include "game/src/ecs/field/field.h"

namespace game::util::pathfinding {
    std::vector<sf::Vector2u> search(
            const ecs::Field &field,
            const sf::Vector2u &start,
            const sf::Vector2u &end
    );
}

#endif //GAME_SEARCH_H
