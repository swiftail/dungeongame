
#include "level_started_message.h"

namespace game::log::message::impl {
    void LevelStartedMessage::print(std::ostream &stream) const {
        stream << "LevelStarted[pos=(" << _pos.x << "," << _pos.y << "),fieldSize=(" << _fieldSize.x << "," << _fieldSize.y << ")]";
    }

    LevelStartedMessage::LevelStartedMessage(const sf::Vector2u &fieldSize, const sf::Vector2u &pos) :
            _fieldSize(fieldSize),
            _pos(pos) {}
} // impl