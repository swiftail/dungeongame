
#ifndef GAME_INTERPOLATION_PROPERTIES_H
#define GAME_INTERPOLATION_PROPERTIES_H

#include "interpolation_property.h"

namespace game::tween::mapping::interpolation {

    template<class T>
    concept ImplicitInterpolationPossible = requires(T a, T b, float c) {
        a + (b - a) * c;
    };

    class InterpolationProperties {
    public:
        InterpolationProperties(InterpolationProperties const &) = delete;

        InterpolationProperties() = delete;

        InterpolationProperties &operator=(InterpolationProperties const &) = delete;

        template<typename N>
        requires ImplicitInterpolationPossible<N>
        static const InterpolationProperty <N> &numeric() {
            static InterpolationProperty<N> instance([](const N &start, const N &end, float progress) {
                return start + (end * progress) - (start * progress);
            });
            return instance;
        }

        static const InterpolationProperty <sf::Color> &color() {
            static InterpolationProperty<sf::Color> instance(
                    [](const sf::Color &start, const sf::Color &end, float progress) {
                        const auto &byteInterpolation = InterpolationProperties::numeric<uint8_t>();

                        return sf::Color(
                                byteInterpolation.apply(start.r, end.r, progress),
                                byteInterpolation.apply(start.g, end.g, progress),
                                byteInterpolation.apply(start.b, end.b, progress),
                                byteInterpolation.apply(start.a, end.a, progress)
                        );
                    }
            );
            return instance;
        }
    };

} // tween

#endif //GAME_INTERPOLATION_PROPERTIES_H
