
#include "text_render_util.h"

namespace game {
    void TextRenderUtil::adjustPositionCentered(sf::Text &text) {
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    }
} // game