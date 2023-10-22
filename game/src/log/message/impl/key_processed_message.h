
#ifndef GAME_KEY_PROCESSED_MESSAGE_H
#define GAME_KEY_PROCESSED_MESSAGE_H

#include "game/src/log/message/message.h"
#include "SFML/Window/Keyboard.hpp"
#include "game/src/ecs/impl/data/move_direction.h"

namespace game::log::message::impl {

    class KeyProcessedMessage : public Message {
    private:
        sf::Keyboard::Key _key;
        ecs::MoveDirection::Enum _command;
    public:
        KeyProcessedMessage(sf::Keyboard::Key key, ecs::MoveDirection::Enum command);

        void print(std::ostream &stream) const override;
    };

} // impl

#endif //GAME_KEY_PROCESSED_MESSAGE_H
