#ifndef GAME_RENDER_CONTEXT_H
#define GAME_RENDER_CONTEXT_H

#include <SFML/Graphics.hpp>
#include <game/src/resource/bundle.h>

namespace game::core::context {

    class RenderContext {
    private:
        const Bundle& _resourceBundle;

        sf::RenderWindow &_window;

        sf::Time _delta;

    public:
        explicit RenderContext(sf::RenderWindow &window, const Bundle& resourceBundle);

        sf::RenderWindow &window() const;

        sf::Time delta() const;

        const Bundle& resourceBundle() const;

        void reset(
                sf::Time &delta
        );
    };

} // game

#endif //GAME_RENDER_CONTEXT_H
