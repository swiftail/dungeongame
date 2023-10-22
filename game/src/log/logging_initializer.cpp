
#include "logging_initializer.h"

namespace game {
    namespace log {
        Logger LoggingInitializer::initialize() {
            std::vector<std::shared_ptr<game::log::appender::Appender>> appenders = {};

            std::cout << "Configuring logging\n";
            if (ask("Logging to stdio?")) {
                appenders.push_back(std::make_shared<game::log::appender::impl::StdioAppender>());
            }
            if (ask("Logging to log.txt?")) {
                appenders.push_back(std::make_shared<game::log::appender::impl::FileAppender>(std::ofstream("./log.txt")));
            }
            std::cout << "Logger configured to use " << appenders.size() << " appenders\n";

            return Logger(appenders);
        }
    } // game
} // log