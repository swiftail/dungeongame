
#ifndef GAME_SCHEMA_H
#define GAME_SCHEMA_H

#include "game/src/ser/buffer/read_buffer.h"
#include "game/src/ser/buffer/write_buffer.h"
#include <memory>

namespace game::ser::schema {

    class Schema {
    public:
        virtual void writeTo(buffer::WriteBuffer& buf) const = 0;
        virtual void readFrom(buffer::ReadBuffer& buf) = 0;
    };

} // schema

#endif //GAME_SCHEMA_H
