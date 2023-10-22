
#include "key_not_processed_message.h"

#include "game/src/fs/config/key_mapping.h"

namespace game::log::message::impl {
    void KeyNotProcessedMessage::print(std::ostream &stream) const {
        stream << "KeyNotProcessed[key=" << fs::config::KeyMapping::instance().keyToString(_key).value_or("null") << "]";
    }

    KeyNotProcessedMessage::KeyNotProcessedMessage(sf::Keyboard::Key key) :
            _key(key) {}
} // impl