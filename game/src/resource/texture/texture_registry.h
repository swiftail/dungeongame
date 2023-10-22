
#ifndef GAME_TEXTURE_REGISTRY_H
#define GAME_TEXTURE_REGISTRY_H

#include "texture_definition.h"
#include "texture_key.h"

namespace game::resource::texture {

    class TextureRegistry {
    private:
        std::map<TextureKey, std::unique_ptr<TextureDefinition>> _data;

        TextureRegistry();

    public:
        TextureRegistry(TextureRegistry const &) = delete;

        TextureRegistry &operator=(TextureRegistry const &) = delete;

        static const TextureRegistry &instance();

        const std::unique_ptr<TextureDefinition> &get(TextureKey key) const;
    };

} // texture

#endif //GAME_TEXTURE_REGISTRY_H
