
#include "path_movement_schema.h"

#include "game/src/util/math.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::entity::enemy::movement {
    sf::Vector2i PathMovementSchema::_move(const Field& field, const sf::Vector2u &currentPosition) {
        auto &targetPosition = _path[_index];
        auto delta = util::math::direction(sf::Vector2i{
                (int32_t) targetPosition.x - (int32_t) currentPosition.x,
                (int32_t) targetPosition.y - (int32_t) currentPosition.y,
        });
        sf::Vector2u result = {
                currentPosition.x + delta.x,
                currentPosition.y + delta.y
        };

        if (result == targetPosition) {
            if (_index == _path.size() - 1) {
                _index = 0;
            } else {
                _index++;
            }
        }

        return game::util::math::transform<int>(result);
    }

    PathMovementSchema::PathMovementSchema(const std::vector<sf::Vector2u> &path) :
            _path(path) {}
} // move_schema