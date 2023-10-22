
#ifndef GAME_SPRITE_RENDER_UTIL_H
#define GAME_SPRITE_RENDER_UTIL_H

#include "SFML/Graphics/Sprite.hpp"

namespace game::graphics::sprite {

    class SpriteRenderUtil {
    public:
        SpriteRenderUtil(SpriteRenderUtil const &) = delete;

        SpriteRenderUtil() = delete;

        SpriteRenderUtil &operator=(SpriteRenderUtil const &) = delete;

        static void centerOrigin(sf::Sprite &sprite);
    };

} // sprite

#endif //GAME_SPRITE_RENDER_UTIL_H
