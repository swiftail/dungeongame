
#ifndef GAME_LEVELS_H
#define GAME_LEVELS_H

#include "game/src/ser/schema/impl/level_schema.h"

namespace game::ecs::level {

    class Levels {
    private:
        static ser::schema::LevelSchema first();

        static ser::schema::LevelSchema second();

    public:
        Levels(Levels const &) = delete;

        Levels() = delete;

        Levels &operator=(Levels const &) = delete;

        static const std::vector<ser::schema::LevelSchema> &levels();
    };

} // Level

#endif //GAME_LEVELS_H
