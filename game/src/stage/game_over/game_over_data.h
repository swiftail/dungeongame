
#ifndef GAME_GAME_OVER_DATA_H
#define GAME_GAME_OVER_DATA_H

#include <cstdint>
#include <cstdlib>
#include "game/src/stage/stage_data.h"

namespace game::stage::game_over {

    class GameOverData : public StageData {
    private:
        bool _isLost;
        uint32_t _score;
        uint32_t _health;
        size_t _levelIndex;
    public:
        GameOverData() = default;

        GameOverData(
                bool isLost,
                uint32_t score,
                uint32_t health,
                size_t levelIndex
        );

        bool isLost() const;

        uint32_t score() const;

        uint32_t health() const;

        size_t levelIndex() const;
    };

} // game_over

#endif //GAME_GAME_OVER_DATA_H
