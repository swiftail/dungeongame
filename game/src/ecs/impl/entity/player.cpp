
#include "player.h"
#include "game/src/util/math.h"

namespace game::ecs {
    Player::Player(
            const sf::Vector2u &fieldSize,
            const sf::Vector2u &start
    ) :
            entity::trait::HasHealth(
                    int32_t_restrict(
                            10,
                            0,
                            10
                    )
            ),
            entity::trait::HasPosition(RestrictedVector<uint32_t>(
                    sf::Vector2u(0, 0),
                    sf::Vector2u(fieldSize.x - 1, fieldSize.y - 1),
                    start
            )),
            entity::trait::Movable(game::util::math::transform<int>(_position.get())),
            _score(int32_t_restrict(
                    std::numeric_limits<int32_t>::max(),
                    0,
                    0
            )),
            _command(MoveDirection::Enum::null) {}


    int32_t_restrict &Player::score() {
        return _score;
    }

    void Player::setCommand(MoveDirection::Enum command) {
        _command = command;
    }

    MoveDirection::Enum Player::command() const {
        return _command;
    }

    bool Player::isAlive() {
        return _health.get() > 0;
    }

    resource::texture::TextureKey Player::textureKey() {
        return resource::texture::TextureKey::PLAYER;
    }
} // ecs