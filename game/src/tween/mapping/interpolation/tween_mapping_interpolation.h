
#ifndef GAME_TWEEN_MAPPING_INTERPOLATION_H
#define GAME_TWEEN_MAPPING_INTERPOLATION_H

#include "property/interpolation_property.h"
#include "function/timing_function.h"
#include "../tween_mapping.h"

namespace game::tween::mapping::interpolation {

    template<typename T>
    class TweenMappingInterpolation : public TweenMapping<T> {
    private:
        T _from;
        T _to;
        const InterpolationProperty<T> &_property;
        const TimingFunction &_timingFunction;
    public:
        TweenMappingInterpolation(TweenMappingInterpolation const &) = delete;

        TweenMappingInterpolation() = delete;

        TweenMappingInterpolation &operator=(TweenMappingInterpolation const &) = delete;

        TweenMappingInterpolation(
                T from,
                T to,
                const InterpolationProperty<T> &property,
                const TimingFunction &timingFunction
        );

        T apply(const timeline::TimelinePoint &timelinePoint) override;;
    };

    template<typename T>
    T TweenMappingInterpolation<T>::apply(const timeline::TimelinePoint &timelinePoint) {
        return _property.apply(_from, _to, _timingFunction.apply(timelinePoint.elapsedPercentClamped()));
    }

    template<typename T>
    TweenMappingInterpolation<T>::TweenMappingInterpolation(T from, T to, const InterpolationProperty<T> &property,
                                                            const TimingFunction &timingFunction) :
            _from(from),
            _to(to),
            _property(property),
            _timingFunction(timingFunction) {}

} // tween

#endif //GAME_TWEEN_MAPPING_INTERPOLATION_H
