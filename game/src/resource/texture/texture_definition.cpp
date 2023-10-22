
#include "texture_definition.h"

namespace game::resource::texture {
    TextureDefinition::TextureDefinition(ImageKey assetKey, const sf::IntRect &textureCoords,
                                         TextureDefinition::Animation animation) :
            _assetKey(assetKey),
            _textureCoords(textureCoords),
            _animation(animation) {}

    void TextureDefinition::applyToSprite(const Bundle &bundle, sf::Sprite &sprite) const {
        sprite.setTexture(bundle.getResource(_assetKey));
        sprite.setTextureRect(_textureCoords);

        int32_t step = (_clock.getElapsedTime().asMilliseconds() / 500) % 4;
        switch (_animation) {
            case Animation::NONE:
                break;
            case Animation::SWING:
                sprite.setPosition(
                        sprite.getPosition().x,
                        sprite.getPosition().y + ((step + 1) % 2) * ((step / 2) * 2 - 1) * 2
                );
                break;
            case Animation::ROTATE:
                sprite.setRotation(90 * step);
                break;
        }
    }
} // texture