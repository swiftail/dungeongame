
#include "button.h"
#include "game/src/graphics/text/text_render_util.h"

namespace game::ui {
    void Button::draw(const core::context::RenderContext &ctx, bool selected) {
        _base.setOutlineThickness(selected ? 4 : 0);

        ctx.window().draw(_base);
        ctx.window().draw(_text);
    }

    void Button::setSize(const sf::Vector2f &size) {
        //_size = size;
        _base.setSize(size);
        _base.setOrigin(size.x / 2, size.y / 2);
    }

    void Button::setCenterPosition(const sf::Vector2f &position) {
        //_position = position;
        _base.setPosition(position);
        _text.setPosition(position);
        TextRenderUtil::adjustPositionCentered(_text);
    }

    void Button::setString(std::string_view str) {
        _text.setString(str.data());
    }

    void Button::setFont(const sf::Font &font) {
        _text.setFont(font);
    }

    int32_t Button::code() {
        return _code;
    }
} // ui