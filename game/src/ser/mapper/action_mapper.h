
#ifndef GAME_ACTION_MAPPER_H
#define GAME_ACTION_MAPPER_H

#include <memory>
#include "game/src/ecs/field/cell/action/cell_action.h"
#include "game/src/ser/schema/impl/cell_schema.h"
#include "game/src/ecs/impl/action/factory/action_factory.h"
#include "game/src/util/type_util.h"

namespace game::ser::mapper {

    class ActionMapper {
    public:
        ActionMapper(ActionMapper const &) = delete;

        ActionMapper() = delete;

        ActionMapper &operator=(ActionMapper const &) = delete;

        static std::optional<std::shared_ptr<game::ecs::CellAction>> from(
                const core::context::InitializeContext& ctx,
                const ecs::ActionFactory &actionFactory,
                schema::CellSchema::Action action,
                const schema::CellSchema::ActionData& data
        );

        static schema::CellSchema::Action to(const game::ecs::CellAction &action);
    };

} // mapper

#endif //GAME_ACTION_MAPPER_H
