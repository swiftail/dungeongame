
#ifndef GAME_RESOURCE_KEY_H
#define GAME_RESOURCE_KEY_H

namespace game {

    namespace resource {
        enum class FontKey {
            FONT
        };
        enum class SoundKey {
            LOADING,
            PICKUP,
            HURT,
            TELEPORT
        };
        enum class MusicKey {
            THEME,
            MENU
        };
        enum class ImageKey {
            BACKGROUND,

            SPRITE_TILES,
            SPRITE_CHAR,

            TRANSPARENT
        };
    };

} // game

#endif //GAME_RESOURCE_KEY_H
