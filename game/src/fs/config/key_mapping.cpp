
#include "key_mapping.h"

namespace game::fs::config {
    const KeyMapping &KeyMapping::instance() {
        static KeyMapping instance;
        return instance;
    }

    std::optional<std::string_view> KeyMapping::keyToString(sf::Keyboard::Key key) const {
        if (!_key2str.contains(key)) {
            return std::nullopt;
        }
        return _key2str.at(key);
    }

    std::optional<sf::Keyboard::Key> KeyMapping::stringToKey(const std::string &string) const {
        if (!_str2key.contains(string)) {
            return std::nullopt;
        }
        return _str2key.at(string);
    }
} // config