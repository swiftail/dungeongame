
#ifndef GAME_TEXTURE_KEY_H
#define GAME_TEXTURE_KEY_H

namespace game::resource::texture {

    enum class TextureKey {
        PLAYER,
        ENEMY_SKULL,
        ENEMY_ZOMBIE,
        ENEMY_PROJECTILE,
        CELL_FLOOR,
        TRANSPARENT,

        CELL_WALL_LEFT,
        CELL_WALL_RIGHT,
        CELL_WALL_TOP,
        CELL_WALL_BOTTOM,
        CELL_WALL_BOTTOM_LEFT,
        CELL_WALL_BOTTOM_RIGHT,
        CELL_WALL_TOP_LEFT,
        CELL_WALL_TOP_RIGHT,

        CELL_TRAPDOOR,
        CELL_LADDER,

        ACTION_ADD_SCORE,
        ACTION_SPIKE,
        ACTION_PORTAL
    };

} // texture

#endif //GAME_TEXTURE_KEY_H
