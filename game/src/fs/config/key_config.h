
#ifndef GAME_KEY_CONFIG_H
#define GAME_KEY_CONFIG_H

#include <map>
#include "game/src/ecs/impl/data/move_direction.h"
#include "SFML/Window/Keyboard.hpp"

namespace game::fs::config {

    class KeyConfig {
    private:
        std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum> _mapping;
    public:
        KeyConfig(KeyConfig &&) = default;

        KeyConfig(KeyConfig const &) = delete;

        KeyConfig() = delete;

        KeyConfig &operator=(KeyConfig const &) = delete;

        KeyConfig(
                const std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum> &mapping
        );

        const std::map<sf::Keyboard::Key, ecs::MoveDirection::Enum>& mapping() const;

        static KeyConfig getDefault();
    };

} // config

#endif //GAME_KEY_CONFIG_H
