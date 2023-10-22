
#ifndef GAME_TWEEN_H
#define GAME_TWEEN_H

#include <game/src/tween/timeline/timeline.h>
#include <game/src/tween/mapping/tween_mapping.h>
#include <game/src/tween/timeline/repeats.h>
#include <game/src/tween/timeline/timeline_point_retriever.h>

#include <iostream>

namespace game::tween {

    class Tween {

    public:
        Tween(Tween const &) = delete;

        Tween() = delete;

        Tween &operator=(Tween const &) = delete;

        template<typename T>
        static T apply(
                const timeline::Timeline &timeline,
                mapping::TweenMapping<T> &mapping,
                const timeline::Repeats &repeats = timeline::Repeats::once(),
                const timeline::Alternation &alternation = timeline::Alternation::NONE
        );

    };

    template<typename T>
    T Tween::apply(
            const timeline::Timeline &timeline,
            mapping::TweenMapping<T> &mapping,
            const timeline::Repeats &repeats,
            const timeline::Alternation &alternation
    ) {
        std::unique_ptr<timeline::TimelinePoint> point = timeline.currentPoint(repeats, alternation);

        return mapping.apply(*point);
    }

} // tween

#endif //GAME_TWEEN_H
