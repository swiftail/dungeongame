
#include "world_data.h"

namespace game {
    namespace stage {
        namespace world {
            WorldData::WorldData(const size_t levelIndex, const ser::schema::LevelSchema &level) :
                    _levelIndex(levelIndex),
                    _level(level) {}

            const ser::schema::LevelSchema &WorldData::level() const {
                return _level;
            }

            size_t WorldData::levelIndex() const {
                return _levelIndex;
            }
        } // game
    } // stage
} // world