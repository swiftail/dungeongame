
#include "level_completed_message.h"

namespace game::log::message::impl {
    void LevelCompletedMessage::print(std::ostream &stream) const {
        stream << "LevelCompleted[score=" << _score << ",health=" << _health << "]";
    }

    LevelCompletedMessage::LevelCompletedMessage(int32_t score, int32_t health) :
            _score(score),
            _health(health) {}
} // impl