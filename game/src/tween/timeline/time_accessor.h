
#ifndef GAME_TIME_ACCESSOR_H
#define GAME_TIME_ACCESSOR_H

#include "SFML/System/Time.hpp"
#include <cstdint>

namespace game::tween::timeline {

    class TimeAccessor {
    public:
        virtual int32_t elapsedTime() const = 0;

        virtual int32_t durationMs() const = 0;

        float elapsedPercent() const;

        int32_t elapsedTimeClamped() const;

        float elapsedPercentClamped() const;

        bool isEnded() const;

        bool isStarted() const;
    };

} // tween

#endif //GAME_TIME_ACCESSOR_H
