
#ifndef GAME_FILES_H
#define GAME_FILES_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace game::fs {

    class Files {
    public:
        Files(Files const &) = delete;

        Files() = delete;

        Files &operator=(Files const &) = delete;

        static std::string readToString(std::string_view path);

        static std::vector<uint8_t> readToBytes(std::string_view path);
    };

} // fs

#endif //GAME_FILES_H
