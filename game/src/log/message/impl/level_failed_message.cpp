
#include "level_failed_message.h"

namespace game::log::message::impl {
    void LevelFailedMessage::print(std::ostream &stream) const {
        stream << "LevelFailed[score=" << _score << ",health=" << _health << ",pos=(" << _pos.x << "," << _pos.y << ")]";
    }

    LevelFailedMessage::LevelFailedMessage(int32_t score, int32_t health, const sf::Vector2u &pos) :
            _score(score),
            _health(health),
            _pos(pos) {}
} // impl