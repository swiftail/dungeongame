
#ifndef GAME_TEXTURE_DEFINITION_H
#define GAME_TEXTURE_DEFINITION_H

#include "game/src/resource/resource_key.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "game/src/resource/bundle.h"
#include "game/src/tween/timeline/timeline.h"

namespace game::resource::texture {

    class TextureDefinition {
    public:
        enum class Animation {
            NONE,
            ROTATE,
            SWING
        };
    private:
        const static inline sf::Clock _clock;

        const ImageKey _assetKey;
        const sf::IntRect _textureCoords;
        const Animation _animation;
    public:
        TextureDefinition(TextureDefinition const &) = delete;

        TextureDefinition() = delete;

        TextureDefinition &operator=(TextureDefinition const &) = delete;

        TextureDefinition(
                ImageKey assetKey,
                const sf::IntRect &textureCoords,
                Animation animation = Animation::NONE
        );

        void applyToSprite(const Bundle &bundle, sf::Sprite &sprite) const;
    };

} // texture

#endif //GAME_TEXTURE_DEFINITION_H
