
#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "game/src/ecs/entity/entity.h"
#include "../data/int32_t_restrict.h"
#include "SFML/System/Vector2.hpp"
#include "../data/restricted_vector.h"
#include "trait/has_position.h"
#include "trait/movable.h"
#include "game/src/tween/tween.h"
#include "game/src/ecs/impl/entity/trait/has_health.h"
#include "game/src/ecs/impl/entity/trait/drawable.h"

namespace game::ecs {

    class Player :
            public entity::Entity,
            public entity::trait::HasPosition,
            public entity::trait::Movable,
            public entity::trait::HasHealth,
            public entity::trait::Drawable {
    private:
        int32_t_restrict _score;
        MoveDirection::Enum _command;

    public:
        Player(const sf::Vector2u &fieldSize,
               const sf::Vector2u &start);

        int32_t_restrict &score();

        void setCommand(MoveDirection::Enum command);

        MoveDirection::Enum command() const;

        bool isAlive() override;

        resource::texture::TextureKey textureKey() override;
    };

} // ecs

#endif //GAME_PLAYER_H
