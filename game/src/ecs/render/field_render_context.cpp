
#include "field_render_context.h"

namespace game::ecs {
    static const sf::Vector2f CELL_DIMENSIONS = sf::Vector2f(16, 16);

    sf::Vector2f FieldRenderContext::getCellRenderPositionCentered(const sf::Vector2u &coords) const {
        return {
                _renderStart.x + (float) coords.x * _cellSize + _cellSize / 2,
                _renderStart.y + (float) coords.y * _cellSize + _cellSize / 2
        };
    }

    sf::Vector2f FieldRenderContext::getCellRenderPosition(const sf::Vector2u &coords) const {
        return {
                _renderStart.x + (float) coords.x * _cellSize,
                _renderStart.y + (float) coords.y * _cellSize
        };
    }

    float FieldRenderContext::cellSize() const {
        return _cellSize;
    }

    void FieldRenderContext::reset(const sf::Window &window, const Field &field) {
        const auto &size = field.size();
        const auto &windowSize = window.getSize();

        auto scaleFactor = sf::Vector2f(
                (float) windowSize.x / (float) size.x,
                (float) windowSize.y / (float) size.y
        );


        _cellSize = std::min(scaleFactor.x, scaleFactor.y);

        _renderSize = sf::Vector2f(
                (float) size.x * _cellSize,
                (float) size.y * _cellSize
        );

        _renderStart = sf::Vector2f(
                ((float) windowSize.x - _renderSize.x) / 2,
                ((float) windowSize.y - _renderSize.y) / 2
        );
    }

    sf::Vector2f FieldRenderContext::getCellSpriteScale(const sf::IntRect &textureRect) const {
        return {
                _cellSize / CELL_DIMENSIONS.x,
                _cellSize / CELL_DIMENSIONS.y
        };
    }

    sf::Vector2f FieldRenderContext::getRenderSize() const {
        return _renderSize;
    }
} // ecs