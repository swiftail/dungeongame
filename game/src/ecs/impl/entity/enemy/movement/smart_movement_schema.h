
#ifndef GAME_SMART_MOVEMENT_SCHEMA_H
#define GAME_SMART_MOVEMENT_SCHEMA_H

#include "SFML/System/Vector2.hpp"

#include "game/src/ecs/impl/entity/trait/has_position.h"
#include "game/src/ecs/field/field.h"

namespace game::ecs::impl::entity::enemy::movement {

    class SmartMovementSchema {
    private:
        game::ecs::entity::trait::HasPosition &_target;
    public:
        SmartMovementSchema(game::ecs::entity::trait::HasPosition& target);

        sf::Vector2i _move(const Field& field, const sf::Vector2u &currentPosition);
    };

} // movement

#endif //GAME_SMART_MOVEMENT_SCHEMA_H
