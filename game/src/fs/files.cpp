
#include "files.h"

namespace game::fs {
    std::string Files::readToString(std::string_view path) {
        std::ifstream stream(path);

        if (!stream) {
            throw std::logic_error("Failed to open file: " + std::string(path));
        }

        std::stringstream buffer;
        buffer << stream.rdbuf();
        return buffer.str();
    }

    std::vector<uint8_t> Files::readToBytes(std::string_view path) {
        std::ifstream stream(path, std::ios::binary | std::ios::ate);

        if (!stream) {
            throw std::logic_error("Failed to open file: " + std::string(path));
        }

        std::ifstream::pos_type pos = stream.tellg();

        if (pos == 0) {
            return std::vector<uint8_t>{};
        }

        std::vector<uint8_t> result(pos);

        stream.seekg(0, std::ios::beg);
        stream.read((char *) &result[0], pos);

        return result;
    }
} // fs