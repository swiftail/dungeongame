
#ifndef GAME_WORLD_DATA_H
#define GAME_WORLD_DATA_H

#include "game/src/ser/schema/impl/level_schema.h"
#include "game/src/stage/stage_data.h"

namespace game::stage::world {

    class WorldData : public StageData {
    private:
        const size_t _levelIndex;
        const ser::schema::LevelSchema &_level;
    public:
        WorldData(
                const size_t levelIndex,
                const ser::schema::LevelSchema &level
        );

        const ser::schema::LevelSchema &level() const;

        size_t levelIndex() const;
    };

} // world

#endif //GAME_WORLD_DATA_H
