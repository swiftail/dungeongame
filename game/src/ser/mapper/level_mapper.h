
#ifndef GAME_LEVEL_MAPPER_H
#define GAME_LEVEL_MAPPER_H

#include <memory>
#include "game/src/ser/schema/impl/level_schema.h"
#include "game/src/ecs/impl/action/factory/action_factory.h"
#include "game/src/ecs/field/field.h"
#include "game/src/ecs/world.h"
#include "action_mapper.h"

namespace game::ser::mapper {

    class LevelMapper {
    public:
        LevelMapper(LevelMapper const &) = delete;

        LevelMapper() = delete;

        LevelMapper &operator=(LevelMapper const &) = delete;

        static std::unique_ptr<game::ecs::World> from(
                const core::context::InitializeContext& ctx,
                const game::ecs::ActionFactory &actionFactory,
                const ser::schema::LevelSchema &schema
        );
    };

} // mapper

#endif //GAME_LEVEL_MAPPER_H
