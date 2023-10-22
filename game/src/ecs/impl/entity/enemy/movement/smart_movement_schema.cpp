
#include "smart_movement_schema.h"

#include "game/src/util/pathfinding/search.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::entity::enemy::movement {

    sf::Vector2i SmartMovementSchema::_move(const Field &field, const sf::Vector2u &currentPosition) {
        auto &position = _target.position();

        if (currentPosition == position.get()) {
            return game::util::math::transform<int>(currentPosition);
        }

        const auto path = game::util::pathfinding::search(field, currentPosition, position.get());

        if (path.size() < 2) {
            return game::util::math::transform<int>(currentPosition);
        }

        return game::util::math::transform<int>(path.at(1));
    }

    SmartMovementSchema::SmartMovementSchema(ecs::entity::trait::HasPosition &target)
            : _target(target) {
    }
} // movement