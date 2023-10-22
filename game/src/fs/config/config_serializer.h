
#ifndef GAME_CONFIG_SERIALIZER_H
#define GAME_CONFIG_SERIALIZER_H

#include "key_config.h"

#include "game/src/fs/files.h"
#include "key_config_parser.h"

#include <iostream>

namespace game::fs::config {

    class ConfigSerializer {
    private:
        std::string _path;
        KeyConfigParser _parser;
    public:
        ConfigSerializer(
                std::string_view path
        );

        KeyConfig read();
    };

} // config

#endif //GAME_CONFIG_SERIALIZER_H
