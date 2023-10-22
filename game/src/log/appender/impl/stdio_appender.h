
#ifndef GAME_STDIO_APPENDER_H
#define GAME_STDIO_APPENDER_H

#include "game/src/log/appender/appender.h"

#include <iostream>
#include <iomanip>
#include <ctime>

namespace game::log::appender::impl {

    class StdioAppender : public Appender {
        void accept(const message::Message *message) override;
    };

} // impl

#endif //GAME_STDIO_APPENDER_H
