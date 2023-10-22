
#ifndef GAME_TIMELINE_H
#define GAME_TIMELINE_H

#include <cstdint>
#include "SFML/System/Clock.hpp"
#include "time_accessor.h"
#include "timeline_point.h"
#include "repeats.h"
#include "alternation.h"

#include <algorithm>

namespace game::tween::timeline {

    class Timeline : public TimeAccessor {
    private:
        int32_t _delayMs;
        int32_t _durationMs;
        sf::Clock _clock;
        bool _isStarted;

        Timeline(int32_t delayMs, int32_t durationMs);

    public:
        Timeline();
        Timeline(sf::Time delay, sf::Time duration);
        Timeline(sf::Time duration);

        Timeline(Timeline const&) = default;
        Timeline& operator=(Timeline const&) = default;

        int32_t elapsedTime() const override;

        int32_t timeUntilCompletion() const;

        int32_t durationMs() const override;

        std::unique_ptr<TimelinePoint> currentPoint(const Repeats& repeats, const Alternation& alternation) const;

        Timeline& start();

        void startDelayed(sf::Time delay);

        void startAfter(const Timeline &firstTimeline);
    };

} // tween

#endif //GAME_TIMELINE_H
