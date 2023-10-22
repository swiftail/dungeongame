
#include "timing_function.h"

namespace game::tween::mapping::interpolation {

    TimingFunction::TimingFunction(std::function<float(float)> mapping) :
            _mapping(std::move(mapping)) {}

    float TimingFunction::apply(float value) const {
        return _mapping(value);
    }

    TimingFunction &TimingFunction::linear() {
        static TimingFunction instance([](float x) {
            return x;
        });
        return instance;
    }

    TimingFunction &TimingFunction::easeIn() {
        static TimingFunction instance([](float x) {
            return 1 - std::cosf(M_PI * x / 2);
        });
        return instance;
    }

    TimingFunction &TimingFunction::easeOut() {
        static TimingFunction instance([](float x) {
            return std::sinf(M_PI * x / 2);
        });
        return instance;
    }

    TimingFunction &TimingFunction::easeInOut() {
        static TimingFunction instance([](float x) {
            return -(std::cosf(M_PI * x) - 1) / 2;
        });
        return instance;
    }
}