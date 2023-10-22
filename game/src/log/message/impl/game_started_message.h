
#ifndef GAME_GAME_STARTED_MESSAGE_H
#define GAME_GAME_STARTED_MESSAGE_H

#include "game/src/log/message/message.h"

namespace game::log::message::impl {

    class GameStartedMessage : public Message {
        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_GAME_STARTED_MESSAGE_H
