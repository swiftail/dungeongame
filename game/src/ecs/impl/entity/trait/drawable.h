
#ifndef GAME_DRAWABLE_H
#define GAME_DRAWABLE_H

#include "game/src/resource/texture/texture_key.h"

namespace game::ecs::entity::trait {

    class Drawable {
    public:
        Drawable() = default;

        Drawable(Drawable const &) = delete;

        Drawable &operator=(Drawable const &) = delete;

        virtual resource::texture::TextureKey textureKey() = 0;
    };

} // trait

#endif //GAME_DRAWABLE_H
