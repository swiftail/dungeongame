
#ifndef GAME_KEY_CONFIG_PARSER_H
#define GAME_KEY_CONFIG_PARSER_H

#include "./key_config.h"

namespace game::fs::config {

    class KeyConfigParser {
    public:
        KeyConfig parse(std::string_view text);
    };

} // config

#endif //GAME_KEY_CONFIG_PARSER_H
