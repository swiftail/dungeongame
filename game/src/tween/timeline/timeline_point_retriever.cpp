
#include "timeline_point_retriever.h"

namespace game::tween::timeline {
    std::unique_ptr<TimelinePoint>
    TimelinePointRetriever::retrieve(const Timeline &timeline, const Repeats &repeats, const Alternation &alternation) {
        int32_t iterationElapsedMs = timeline.elapsedTime() % timeline.durationMs();
        uint64_t iteration = timeline.elapsedTime() / timeline.durationMs();

        if (alternation == Alternation::ALTERNATE && iteration % 2 != 0) {
            iterationElapsedMs = timeline.durationMs() - iterationElapsedMs;
        }

        if (iteration + 1 > repeats.count() && !repeats.isInfinite()) {
            return std::make_unique<TimelinePoint>(
                    timeline.durationMs(),
                    timeline.durationMs()
            );
        }

        return std::make_unique<TimelinePoint>(
                iterationElapsedMs,
                timeline.durationMs()
        );
    }
} // tween