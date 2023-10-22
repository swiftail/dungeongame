
#ifndef GAME_TIMING_FUNCTION_H
#define GAME_TIMING_FUNCTION_H

#include <functional>
#include <utility>

namespace game::tween::mapping::interpolation {

    class TimingFunction {
    private:
        std::function<float(float)> _mapping;

        TimingFunction(std::function<float(float)> mapping);

    public:
        TimingFunction(TimingFunction const &) = delete;

        TimingFunction() = delete;

        TimingFunction &operator=(TimingFunction const &) = delete;

        float apply(float value) const;

        static TimingFunction &linear();

        static TimingFunction &easeIn();

        static TimingFunction &easeOut();

        static TimingFunction &easeInOut();
    };

} // tween

#endif //GAME_TIMING_FUNCTION_H
