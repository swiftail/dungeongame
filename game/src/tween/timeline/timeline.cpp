
#include "timeline.h"

#include "timeline_point_retriever.h"

namespace game::tween::timeline {
    int32_t Timeline::elapsedTime() const {
        if (!_isStarted) {
            return 0;
        }

        int32_t elapsedMs = _clock.getElapsedTime().asMilliseconds();
        if (elapsedMs >= _delayMs) {
            return elapsedMs - _delayMs;
        } else {
            return 0;
        }
    }

    int32_t Timeline::durationMs() const {
        return _durationMs;
    }

    Timeline::Timeline(int32_t delayMs, int32_t durationMs) :
            _delayMs(delayMs),
            _durationMs(durationMs),
            _isStarted(false) {}

    Timeline::Timeline(sf::Time delay, sf::Time duration) :
            Timeline(delay.asMilliseconds(), duration.asMilliseconds()) {}

    Timeline::Timeline(sf::Time duration) :
            Timeline(0, duration.asMilliseconds()) {}

    Timeline::Timeline() : Timeline(0, 0) {}

    int32_t Timeline::timeUntilCompletion() const {
        return std::max(_delayMs + _durationMs - _clock.getElapsedTime().asMilliseconds(), 0);
    }

    std::unique_ptr<TimelinePoint>
    Timeline::currentPoint(const Repeats &repeats, const Alternation &alternation) const {
        return TimelinePointRetriever::retrieve(*this, repeats, alternation);
    }

    Timeline& Timeline::start() {
        _isStarted = true;
        _clock.restart();
        return *this;
    }

    void Timeline::startDelayed(sf::Time delay) {
        _delayMs = delay.asMilliseconds();
        start();
    }

    void Timeline::startAfter(const Timeline &firstTimeline) {
        _delayMs = firstTimeline.timeUntilCompletion();
        start();
    }

} // tween