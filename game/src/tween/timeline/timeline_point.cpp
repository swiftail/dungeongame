#include "timeline_point.h"

namespace game::tween::timeline {

    int32_t TimelinePoint::elapsedTime() const {
        return _elapsedMs;
    }

    int32_t TimelinePoint::durationMs() const {
        return _durationMs;
    }
}