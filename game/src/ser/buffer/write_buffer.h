
#ifndef GAME_WRITE_BUFFER_H
#define GAME_WRITE_BUFFER_H

#include <cstdint>
#include <cstdlib>
#include <vector>

namespace game::ser::buffer {

    class WriteBuffer {
    private:
        std::unique_ptr<std::vector<uint8_t>> _data = std::make_unique<std::vector<uint8_t>>();

    public:
        void write(const uint8_t *data, size_t size);

        std::unique_ptr<std::vector<uint8_t>> flush();
    };

} // buffer

#endif //GAME_WRITE_BUFFER_H
