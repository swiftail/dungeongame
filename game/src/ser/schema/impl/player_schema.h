
#ifndef GAME_PLAYER_SCHEMA_H
#define GAME_PLAYER_SCHEMA_H

#include <cstdint>
#include "SFML/System/Vector2.hpp"
#include "game/src/ecs/impl/data/move_direction.h"
#include "game/src/ser/schema/schema.h"

#include "game/src/ser/buffer/readers.h"
#include "game/src/ser/buffer/writers.h"

namespace game::ser::schema {

    struct PlayerSchema : public Schema {
    private:
        uint32_t _health;
        uint32_t _score;
        sf::Vector2u _position;
        ecs::MoveDirection::Enum _direction;
        ecs::MoveDirection::Enum _lastDirection;

    public:
        PlayerSchema() = default;

        PlayerSchema(
                uint32_t health,
                uint32_t score,
                sf::Vector2u position,
                ecs::MoveDirection::Enum direction,
                ecs::MoveDirection::Enum lastDirection
        );

        void readFrom(buffer::ReadBuffer &buf) override;

        void writeTo(buffer::WriteBuffer &buf) const override;
    };

} // schema

#endif //GAME_PLAYER_SCHEMA_H
