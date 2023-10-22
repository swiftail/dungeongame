#include "render_context.h"


namespace game::core::context {
    RenderContext::RenderContext(sf::RenderWindow &window, const Bundle &resourceBundle) :
            _window(window),
            _resourceBundle(resourceBundle) {}

    sf::RenderWindow &RenderContext::window() const {
        return _window;
    }

    sf::Time RenderContext::delta() const {
        return _delta;
    }

    const Bundle &RenderContext::resourceBundle() const {
        return _resourceBundle;
    }

    void RenderContext::reset(
            sf::Time &delta
    ) {
        _delta = delta;
    }
} // game