
#include "message.h"

namespace game {
    namespace log {
        std::ostream &message::operator<<(std::ostream &stream, const message::Message *data) {
            data->print(stream);
            return stream;
        }
    } // game
} // log