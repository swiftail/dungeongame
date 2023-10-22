
#ifndef GAME_READERS_H
#define GAME_READERS_H

#include "read_buffer.h"

namespace game::ser::buffer::readers {
    template<typename T>
    T readPrimitive(ReadBuffer& buf) {
        return *reinterpret_cast<const T *>(buf.read(sizeof(T)));
    }

    template<typename T>
    T readSchema(ReadBuffer& buf) {
        T t;
        t.readFrom(buf);
        return t;
    }

    template <typename T>
    T readImplicit(ReadBuffer& buf) {
        return _implRead<T>(buf);
    }

    template<typename T>
    void _implRead(buffer::ReadBuffer &buf) {
    }
}

#endif //GAME_READERS_H
