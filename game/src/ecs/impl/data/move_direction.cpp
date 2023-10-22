
#include "move_direction.h"

#include "map"

namespace game::ecs {
    MoveDirection::Enum MoveDirection::fromString(std::string_view str) {
        if (str == "LEFT") {
            return Enum::LEFT;
        }
        if (str == "RIGHT") {
            return Enum::RIGHT;
        }
        if (str == "UP") {
            return Enum::UP;
        }
        if (str == "DOWN") {
            return Enum::DOWN;
        }
        return Enum::null;
    }

    const std::string &MoveDirection::toString(MoveDirection::Enum value) {
        static std::string null = "null";
        static std::string LEFT = "LEFT";
        static std::string RIGHT = "RIGHT";
        static std::string UP = "UP";
        static std::string DOWN = "DOWN";

        switch (value) {
            case Enum::null:
                return null;
            case Enum::LEFT:
                return LEFT;
            case Enum::RIGHT:
                return RIGHT;
            case Enum::UP:
                return UP;
            case Enum::DOWN:
                return DOWN;
        }
    }

    sf::Vector2i MoveDirection::unitVector(const MoveDirection::Enum &value) {
        std::map<MoveDirection::Enum, sf::Vector2i> data = {
                {Enum::null, {0,0}},
                {Enum::LEFT, {-1,0}},
                {Enum::RIGHT, {1,0}},
                {Enum::UP, {0,-1}},
                {Enum::DOWN, {0,1}},
        };

        return data[value];
    }
} // ecs