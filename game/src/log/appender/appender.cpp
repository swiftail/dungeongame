
#include "appender.h"

namespace game {
    namespace log {
        std::string appender::Appender::prefix() {
            auto t = std::time(nullptr);
            auto tm = *std::localtime(&t);
            std::stringstream ss;
            ss << std::put_time(&tm, "[%d.%m.%Y %H:%M:%S] ");
            return ss.str();
        }
    } // game
} // log