
#ifndef GAME_MOVE_DIRECTION_H
#define GAME_MOVE_DIRECTION_H

#include "SFML/System/Vector2.hpp"
#include <string>

namespace game::ecs {

    class MoveDirection {
    public:
        MoveDirection(MoveDirection const &) = delete;

        MoveDirection() = delete;

        MoveDirection &operator=(MoveDirection const &) = delete;

        enum class Enum {
            null,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };

        static sf::Vector2i unitVector(const Enum& value);

        static Enum fromString(std::string_view str);

        static const std::string& toString(Enum value);

    };

    // game
} // ecs

#endif //GAME_MOVE_DIRECTION_H
