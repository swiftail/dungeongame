
#include "logger.h"

namespace game {
    namespace log {
        Logger::Logger(std::vector<std::shared_ptr<appender::Appender>> appenders) : _appenders(std::move(appenders)) {}

        void Logger::log(std::unique_ptr<message::Message> message) {
            for (auto &item: this->_appenders) {
                item->accept(message.get());
            }
        }
    } // game
} // log