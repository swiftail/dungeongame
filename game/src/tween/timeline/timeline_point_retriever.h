
#ifndef GAME_TIMELINE_POINT_RETRIEVER_H
#define GAME_TIMELINE_POINT_RETRIEVER_H

#include "timeline_point.h"
#include "timeline.h"
#include "repeats.h"
#include "alternation.h"

namespace game::tween::timeline {

    class TimelinePointRetriever {
    public:
        TimelinePointRetriever(TimelinePointRetriever const &) = delete;

        TimelinePointRetriever() = delete;

        TimelinePointRetriever &operator=(TimelinePointRetriever const &) = delete;

        static std::unique_ptr<TimelinePoint> retrieve(
                const Timeline &timeline,
                const Repeats &repeats,
                const Alternation &alternation
        );

    };

} // tween

#endif //GAME_TIMELINE_POINT_RETRIEVER_H
