
#ifndef GAME_APPENDER_H
#define GAME_APPENDER_H

#include "game/src/log/message/message.h"
#include <sstream>
#include <iomanip>

namespace game::log::appender {

    class Appender {
    protected:
        static std::string prefix();
    public:
        virtual void accept(const message::Message* message) = 0;
    };

} // log

#endif //GAME_APPENDER_H
