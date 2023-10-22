
#include "movable.h"

namespace game::ecs::entity::trait {

    const sf::Vector2i &Movable::targetPosition() {
        return _targetPosition;
    }

    void Movable::setTargetPosition(const sf::Vector2i &position) {
        _targetPosition = position;
    }

    Movable::Movable(const sf::Vector2i &targetPosition)
            : _targetPosition(targetPosition) {}
}