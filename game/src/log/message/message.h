
#ifndef GAME_MESSAGE_H
#define GAME_MESSAGE_H

#include "ostream"

namespace game::log::message {

    class Message {
    protected:
        virtual void print(std::ostream& stream) const = 0;
    public:
        friend std::ostream& operator<< (std::ostream& stream, const Message* data);

        virtual ~Message() = default;
    };

} // log

#endif //GAME_MESSAGE_H
