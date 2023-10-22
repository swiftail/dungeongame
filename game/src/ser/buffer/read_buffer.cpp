
#include "read_buffer.h"

namespace game::ser::buffer {
    const uint8_t *ReadBuffer::read(size_t size) {
        if (_data->size() - _index < size) {
            // todo very bad
        }

        const uint8_t *result = _data->data() + _index;
        _index += size;

        return result;
    }

    ReadBuffer::ReadBuffer(std::unique_ptr<std::vector<uint8_t>> data) :
            _data(std::move(data)),
            _index(0) {}
} // buffer