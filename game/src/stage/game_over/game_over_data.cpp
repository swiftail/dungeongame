
#include "game_over_data.h"

namespace game::stage::game_over {
    GameOverData::GameOverData(bool isLost, uint32_t score, uint32_t health, size_t levelIndex) :
            _isLost(isLost),
            _score(score),
            _health(health),
            _levelIndex(levelIndex){}

    uint32_t GameOverData::health() const {
        return _health;
    }

    bool GameOverData::isLost() const {
        return _isLost;
    }

    uint32_t GameOverData::score() const {
        return _score;
    }

    size_t GameOverData::levelIndex() const {
        return _levelIndex;
    }
} // game_over