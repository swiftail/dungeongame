
#include "sprite_render_util.h"

namespace game {
    namespace graphics {
        namespace sprite {
            void SpriteRenderUtil::centerOrigin(sf::Sprite &sprite) {
                sprite.setOrigin(
                        (float) sprite.getTextureRect().width / 2,
                        (float) sprite.getTextureRect().height / 2
                );
            }
        } // game
    } // graphics
} // sprite