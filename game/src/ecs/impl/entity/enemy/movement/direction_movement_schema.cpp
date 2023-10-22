
#include "direction_movement_schema.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::entity::enemy::movement {

    DirectionMovementSchema::DirectionMovementSchema(const sf::Vector2i &direction) :
            _direction(direction) {
    }

    sf::Vector2i DirectionMovementSchema::_move(const Field &field, const sf::Vector2u &currentPosition) {
        return game::util::math::transform<int>(currentPosition) + this->_direction;
    }
} // movement