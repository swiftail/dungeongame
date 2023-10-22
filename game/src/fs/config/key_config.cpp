
#include "key_config.h"

namespace game::fs::config {
    KeyConfig::KeyConfig(const std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum> &mapping) : _mapping(mapping) {}

    const std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum> &KeyConfig::mapping() const {
        return _mapping;
    }

    KeyConfig KeyConfig::getDefault() {
        return {
                {
                        { sf::Keyboard::Key::Left, ecs::MoveDirection::Enum::LEFT},
                        { sf::Keyboard::Key::Right,ecs::MoveDirection::Enum::RIGHT},
                        { sf::Keyboard::Key::Up,ecs::MoveDirection::Enum::UP},
                        { sf::Keyboard::Key::Down,ecs::MoveDirection::Enum::DOWN},
                }
        };
    }
} // config