
#ifndef GAME_KEY_NOT_PROCESSED_MESSAGE_H
#define GAME_KEY_NOT_PROCESSED_MESSAGE_H

#include "game/src/log/message/message.h"
#include "SFML/Window/Keyboard.hpp"

namespace game::log::message::impl {

    class KeyNotProcessedMessage : public Message {
    private:
        sf::Keyboard::Key _key;
    public:
        KeyNotProcessedMessage(sf::Keyboard::Key key);

        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_KEY_NOT_PROCESSED_MESSAGE_H
