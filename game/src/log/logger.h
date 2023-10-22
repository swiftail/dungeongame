
#ifndef GAME_LOGGER_H
#define GAME_LOGGER_H

#include <vector>
#include "game/src/log/appender/appender.h"

namespace game::log {

    class Logger {
    private:
        std::vector<std::shared_ptr<appender::Appender>> _appenders;
    public:
        Logger(Logger &&) = default;

        Logger(Logger const &) = delete;

        Logger() = delete;

        Logger &operator=(Logger const &) = delete;

        explicit Logger(std::vector<std::shared_ptr<appender::Appender>> appenders);

        void log(std::unique_ptr<message::Message> message);
    };

} // log

#endif //GAME_LOGGER_H
