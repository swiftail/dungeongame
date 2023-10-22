
#ifndef GAME_LEVEL_STARTED_MESSAGE_H
#define GAME_LEVEL_STARTED_MESSAGE_H

#include "game/src/log/message/message.h"
#include "SFML/System/Vector2.hpp"

namespace game::log::message::impl {

    class LevelStartedMessage : public Message {
    private:
        sf::Vector2u _fieldSize;
        sf::Vector2u _pos;
    public:
        LevelStartedMessage(const sf::Vector2u &fieldSize, const sf::Vector2u &pos);

        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_LEVEL_STARTED_MESSAGE_H
