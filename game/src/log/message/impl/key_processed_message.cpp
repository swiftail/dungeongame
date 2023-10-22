
#include "key_processed_message.h"
#include "game/src/fs/config/key_mapping.h"

namespace game::log::message::impl {
    void KeyProcessedMessage::print(std::ostream &stream) const {
        stream << "KeyProcessed[key="
               << fs::config::KeyMapping::instance().keyToString(_key).value_or("null")
               << ",command="
               << ecs::MoveDirection::toString(_command)
               << "]";
    }

    KeyProcessedMessage::KeyProcessedMessage(sf::Keyboard::Key key, ecs::MoveDirection::Enum command) :
            _key(key),
            _command(command) {}
} // impl