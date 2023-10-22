
#include "file_appender.h"

namespace game::log::appender::impl {
    void FileAppender::accept(const message::Message *message) {
        _stream << prefix() << message << '\n';
    }
} // impl