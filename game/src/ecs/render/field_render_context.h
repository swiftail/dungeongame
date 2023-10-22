
#ifndef GAME_FIELD_RENDER_CONTEXT_H
#define GAME_FIELD_RENDER_CONTEXT_H

#include <SFML/Graphics.hpp>
#include "../field/field.h"

namespace game::ecs {

    class FieldRenderContext {
    private:
        float _cellSize;
        sf::Vector2f _renderStart;
        sf::Vector2f _renderSize;
    public:
        void reset(
                const sf::Window &window,
                const Field &field
        );

        float cellSize() const;

        sf::Vector2f getCellRenderPosition(const sf::Vector2u &coords) const;

        sf::Vector2f getCellRenderPositionCentered(const sf::Vector2u &coords) const;

        sf::Vector2f getCellSpriteScale(const sf::IntRect &textureRect) const;

        sf::Vector2f getRenderSize() const;
    };

} // ecs

#endif //GAME_FIELD_RENDER_CONTEXT_H
