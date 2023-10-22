
#include "player_schema.h"

namespace game::ser::schema {
    void PlayerSchema::readFrom(buffer::ReadBuffer &buf) {
        using namespace buffer::readers;
        _health = readPrimitive<uint32_t>(buf);
        _score = readPrimitive<uint32_t>(buf);
        _position = readPrimitive<sf::Vector2u>(buf);
        _direction = readPrimitive<ecs::MoveDirection::Enum>(buf);
        _lastDirection = readPrimitive<ecs::MoveDirection::Enum>(buf);
    }

    void PlayerSchema::writeTo(buffer::WriteBuffer &buf) const {
        using namespace buffer::writers;
        writePrimitive<uint32_t>(buf, _health);
        writePrimitive<uint32_t>(buf, _score);
        writePrimitive<sf::Vector2u>(buf, _position);
        writePrimitive<ecs::MoveDirection::Enum>(buf, _direction);
        writePrimitive<ecs::MoveDirection::Enum>(buf, _lastDirection);
    }

    PlayerSchema::PlayerSchema(uint32_t health, uint32_t score, sf::Vector2u position,
                               ecs::MoveDirection::Enum direction, ecs::MoveDirection::Enum lastDirection) :
            _health(health),
            _score(score),
            _position(position),
            _direction(direction),
            _lastDirection(lastDirection) {}
} // schema