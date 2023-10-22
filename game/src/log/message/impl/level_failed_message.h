
#ifndef GAME_LEVEL_FAILED_MESSAGE_H
#define GAME_LEVEL_FAILED_MESSAGE_H

#include "game/src/log/message/message.h"
#include "SFML/System/Vector2.hpp"

namespace game::log::message::impl {

    class LevelFailedMessage : public Message {
    private:
        int32_t _score;
        int32_t _health;
        sf::Vector2u _pos;
    public:
        LevelFailedMessage(int32_t score, int32_t health, const sf::Vector2u& pos);

        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_LEVEL_FAILED_MESSAGE_H
