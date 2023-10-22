
#ifndef GAME_WRITERS_H
#define GAME_WRITERS_H

#include "write_buffer.h"

namespace game::ser::buffer::writers {
    template<typename T>
    void writePrimitive(WriteBuffer &buf, const T &data) {
        buf.write(
                reinterpret_cast<const uint8_t *>(&data),
                sizeof(T)
        );
    }

    template<typename T>
    void writeSchema(WriteBuffer &buf, const T &data) {
        data.writeTo(buf);
    }

    template<typename T>
    void writeImplicit(WriteBuffer &buf, const T &data) {
        return _implWrite<T>(buf);
    }

    template<typename T>
    void _implWrite(buffer::WriteBuffer &buf, const T &data) {
    }
}

#endif //GAME_WRITERS_H
