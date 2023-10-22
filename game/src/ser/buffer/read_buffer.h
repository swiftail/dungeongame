
#ifndef GAME_READ_BUFFER_H
#define GAME_READ_BUFFER_H

#include <cstdint>
#include <cstdio>
#include <memory>
#include <vector>

namespace game::ser::buffer {

    class ReadBuffer {
    private:
        std::unique_ptr<std::vector<uint8_t>> _data;
        size_t _index;

    public:
        ReadBuffer(std::unique_ptr<std::vector<uint8_t>> data);

        const uint8_t *read(size_t size);
    };

} // buffer

#endif //GAME_READ_BUFFER_H
