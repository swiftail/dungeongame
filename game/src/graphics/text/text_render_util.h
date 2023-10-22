
#ifndef GAME_TEXT_RENDER_UTIL_H
#define GAME_TEXT_RENDER_UTIL_H

#include "SFML/Graphics/Text.hpp"

namespace game {

    class TextRenderUtil {
    public:
        TextRenderUtil(TextRenderUtil const &) = delete;

        TextRenderUtil() = delete;

        TextRenderUtil &operator=(TextRenderUtil const &) = delete;

        static void adjustPositionCentered(sf::Text &text);
    };

} // game

#endif //GAME_TEXT_RENDER_UTIL_H
