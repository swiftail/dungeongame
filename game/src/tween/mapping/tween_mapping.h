
#ifndef GAME_TWEEN_MAPPING_H
#define GAME_TWEEN_MAPPING_H

#include <game/src/tween/timeline/timeline_point.h>

namespace game::tween::mapping {

    template<typename T>
    class TweenMapping {
    public:
        virtual T apply(const timeline::TimelinePoint& timelinePoint) = 0;
    };

} // tween

#endif //GAME_TWEEN_MAPPING_H
