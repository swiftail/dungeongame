
#ifndef GAME_MATH_H
#define GAME_MATH_H

#include <cstdio>
#include <cmath>
#include "SFML/System/Vector2.hpp"

namespace game::util::math {
    template <typename T> int32_t sgn(T val) {
        return (T(0) < val) - (val < T(0));
    }

    template<typename T>
    sf::Vector2f normalize(const sf::Vector2<T> &vec) {
        auto len = length(vec);
        return {
                vec.x / len,
                vec.y / len
        };
    }

    template<typename T>
    sf::Vector2<int32_t> direction(const sf::Vector2<T> &vec) {
        return {
                sgn(vec.x),
                sgn(vec.y)
        };
    }

    template<typename T>
    T length(const sf::Vector2<T> &vec) {
        return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    }

    template <typename R, typename S>
    sf::Vector2<R> transform(const sf::Vector2<S>& src) {
        return {(R)src.x,(R)src.y};
    }
}

#endif //GAME_MATH_H
