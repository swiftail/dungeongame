
#include "stdio_appender.h"

namespace game::log::appender::impl {
    void StdioAppender::accept(const message::Message *message) {
        std::cout << prefix() << message << '\n';
    }
} // impl