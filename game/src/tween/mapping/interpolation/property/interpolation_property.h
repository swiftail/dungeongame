
#ifndef GAME_INTERPOLATION_PROPERTY_H
#define GAME_INTERPOLATION_PROPERTY_H

#include <functional>

namespace game::tween::mapping::interpolation {

    template<typename T>
    class InterpolationProperty {
    private:
        std::function<T(const T &, const T &, float)> _mapping;
    public:
        T apply(const T &start, const T &end, float progress) const;

        InterpolationProperty(std::function<T(const T &, const T &, float)> mapping);
    };

    template<typename T>
    InterpolationProperty<T>::InterpolationProperty(std::function<T(const T &, const T &, float)> mapping) :
            _mapping(std::move(mapping)) {}

    template<typename T>
    T InterpolationProperty<T>::apply(const T &start, const T &end, float progress) const {
        return _mapping(start, end, progress);
    }

} // tween

#endif //GAME_INTERPOLATION_PROPERTY_H
