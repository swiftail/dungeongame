#include "time_accessor.h"

#include <algorithm>

namespace game::tween::timeline {
    float TimeAccessor::elapsedPercent() const {
        return (float) elapsedTime() / (float) durationMs();
    }

    int32_t TimeAccessor::elapsedTimeClamped() const {
        return std::min(
                elapsedTime(),
                durationMs()
        );
    }

    float TimeAccessor::elapsedPercentClamped() const {
        return (float) elapsedTimeClamped() / (float) durationMs();
    }

    bool TimeAccessor::isEnded() const {
        return elapsedPercentClamped() == 1;
    }

    bool TimeAccessor::isStarted() const {
        return elapsedTimeClamped() != 0;
    }
}