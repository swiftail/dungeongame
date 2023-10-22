
#include "write_buffer.h"

namespace game::ser::buffer {
    void WriteBuffer::write(const uint8_t *data, size_t size) {
        _data->insert(_data->end(), &data[0], &data[size]);
    }

    std::unique_ptr<std::vector<uint8_t>> WriteBuffer::flush() {
        return std::move(_data);
    }
} // buffer