
#ifndef GAME_TIMELINE_POINT_H
#define GAME_TIMELINE_POINT_H

#include <cstdint>

#include "time_accessor.h"

namespace game::tween::timeline {

    class TimelinePoint : public TimeAccessor {
    private:
        int32_t _elapsedMs;
        int32_t _durationMs;
    public:
        TimelinePoint(int32_t elapsedMs, int32_t durationMs) :
                _elapsedMs(elapsedMs),
                _durationMs(durationMs) {}

        int32_t elapsedTime() const override;

        int32_t durationMs() const override;
    };

} // tween

#endif //GAME_TIMELINE_POINT_H
