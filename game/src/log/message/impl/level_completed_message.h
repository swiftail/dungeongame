
#ifndef GAME_LEVEL_COMPLETED_MESSAGE_H
#define GAME_LEVEL_COMPLETED_MESSAGE_H

#include "game/src/log/message/message.h"

namespace game::log::message::impl {

    class LevelCompletedMessage : public Message {
    private:
        int32_t _score;
        int32_t _health;
    public:
        LevelCompletedMessage(int32_t score, int32_t health);

        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_LEVEL_COMPLETED_MESSAGE_H
