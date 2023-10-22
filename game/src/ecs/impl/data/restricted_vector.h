
#ifndef GAME_RESTRICTED_VECTOR_H
#define GAME_RESTRICTED_VECTOR_H

#include <algorithm>
#include "SFML/System/Vector2.hpp"

namespace game::ecs {

    template<typename N>
    class RestrictedVector {
    private:
        sf::Vector2<N> _minInclusive;
        sf::Vector2<N> _maxInclusive;
        sf::Vector2<N> _value;
    public:
        RestrictedVector(
                const sf::Vector2<N> &minInclusive,
                const sf::Vector2<N> &maxInclusive,
                const sf::Vector2<N> &initialValue
        ) :
                _minInclusive(minInclusive),
                _maxInclusive(maxInclusive),
                _value(initialValue) {
        }

        template<typename T>
        const sf::Vector2<N> &set(const sf::Vector2<T> &value) {
            auto x = (N) std::clamp(value.x, (T) _minInclusive.x, (T) _maxInclusive.x);
            auto y = (N) std::clamp(value.y, (T) _minInclusive.y, (T) _maxInclusive.y);

            _value.x = x;
            _value.y = y;

            return _value;
        }

        const sf::Vector2<N> &get() const {
            return _value;
        }
    };

} // ecs

#endif //GAME_RESTRICTED_VECTOR_H
