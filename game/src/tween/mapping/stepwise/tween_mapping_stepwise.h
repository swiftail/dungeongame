
#ifndef GAME_TWEEN_MAPPING_STEPWISE_H
#define GAME_TWEEN_MAPPING_STEPWISE_H

#include <cstdlib>
#include <map>

#include "../tween_mapping.h"

#include <iostream>

namespace game::tween::mapping::stepwise {

    template<typename T>
    class TweenMappingStepwise : public TweenMapping<T> {
    private:
        size_t _index = 0;
        T _value;
        T _initialValue;
        std::vector<std::pair<size_t, T>> _data;

    public:
        TweenMappingStepwise(TweenMappingStepwise const &) = delete;

        TweenMappingStepwise() = delete;

        TweenMappingStepwise &operator=(TweenMappingStepwise const &) = delete;

        TweenMappingStepwise(
                T initialValue,
                std::initializer_list<std::pair<size_t, T>> data
        );

        T apply(const timeline::TimelinePoint &timelinePoint) override;
    };

    template<typename T>
    T TweenMappingStepwise<T>::apply(const timeline::TimelinePoint &timelinePoint) {
        uint64_t time = timelinePoint.elapsedTime();

        if (_index != 0 && time < _data.at(_index - 1).first) {
            _index = 0;
            _value = _initialValue;
        }

        while (_index < _data.size()) {
            std::pair<size_t, T> threshold = _data.at(_index);
            if (time >= threshold.first) {
                _value = threshold.second;
                _index++;
            } else {
                break;
            }
        }

        return _value;
    }

    template<typename T>
    TweenMappingStepwise<T>::TweenMappingStepwise(
            T initialValue,
            std::initializer_list<std::pair<size_t, T>> data
    ) : _value(initialValue), _initialValue(initialValue) {
        _data = std::vector(data);
    }

} // game

#endif //GAME_TWEEN_MAPPING_STEPWISE_H
