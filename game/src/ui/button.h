
#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include "game/src/core/context/render_context.h"
#include "game/src/core/context/initialize_context.h"

namespace game::ui {

    class Button {
    private:
        sf::RectangleShape _base;
        sf::Text _text;
        int32_t _code;

    public:
        Button(std::string_view str, size_t code) : _code(code) {
            _text.setCharacterSize(32);
            setString(str);

            _base.setOutlineColor(sf::Color::White);
            _base.setFillColor(sf::Color::Black);
            _text.setFillColor(sf::Color::White);
        }

        void draw(const core::context::RenderContext &ctx, bool selected);

        void setSize(const sf::Vector2f &size);

        void setCenterPosition(const sf::Vector2f &position);

        void setString(std::string_view str);

        void setFont(const sf::Font &font);

        int32_t code();
    };

} // ui

#endif //GAME_BUTTON_H
