
#include "int32_t_restrict.h"

namespace game::ecs {
    int32_t_restrict::int32_t_restrict(int32_t maxValue, int32_t minValue, int32_t initialValue) :
            _maxValue(maxValue),
            _minValue(minValue),
            _value(initialValue) {}

    int32_t int32_t_restrict::get() const {
        return _value;
    }

    int32_t int32_t_restrict::set(int32_t value) {
        _value = std::clamp(value, _minValue, _maxValue);
        return _value;
    }

    float int32_t_restrict::ratio() const {
        if (_maxValue == _minValue) return 1;
        return (float) (_value - _minValue) / (float) (_maxValue - _minValue);
    }

    int32_t int32_t_restrict::add(int32_t value) {
        return set(get() + value);
    }

} // ecs