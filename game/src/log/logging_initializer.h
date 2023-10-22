
#ifndef GAME_LOGGING_INITIALIZER_H
#define GAME_LOGGING_INITIALIZER_H

#include "logger.h"
#include "game/src/log/appender/impl/stdio_appender.h"
#include "game/src/log/appender/impl/file_appender.h"

#include <iostream>

namespace game::log {

    class LoggingInitializer {
    private:
        bool ask(std::string_view text) {
            std::cout << text << " [y/n] ";
            std::string ans;
            getline(std::cin, ans);
            return !ans.empty() && tolower(ans[0]) == 'y';
        }

    public:
        LoggingInitializer() = default;

        LoggingInitializer(LoggingInitializer const &) = delete;

        LoggingInitializer &operator=(LoggingInitializer const &) = delete;

        Logger initialize();
    };

} // log

#endif //GAME_LOGGING_INITIALIZER_H
