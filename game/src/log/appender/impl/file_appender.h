
#ifndef GAME_FILE_APPENDER_H
#define GAME_FILE_APPENDER_H

#include "game/src/log/appender/appender.h"

#include <fstream>

namespace game::log::appender::impl {

    class FileAppender : public Appender {
    private:
        std::ofstream _stream;

    public:
        FileAppender(std::ofstream stream) : _stream(std::move(stream)) {}

        void accept(const message::Message *message) override;
    };

} // impl

#endif //GAME_FILE_APPENDER_H
