
#include "game_started_message.h"

namespace game::log::message::impl {
    void GameStartedMessage::print(std::ostream &stream) const {
        stream << "Game started";
    }
} // impl