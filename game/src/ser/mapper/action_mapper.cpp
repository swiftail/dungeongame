
#include "action_mapper.h"

namespace game::ser::mapper {
    std::optional<std::shared_ptr<game::ecs::CellAction>>
    ActionMapper::from(const core::context::InitializeContext &ctx, const ecs::ActionFactory &actionFactory,
                       schema::CellSchema::Action action, const schema::CellSchema::ActionData &data) {
        switch (action) {
            case schema::CellSchema::Action::ADD_SCORE:
                return actionFactory.addScore();
            case schema::CellSchema::Action::SPIKE:
                return actionFactory.spike();
            case schema::CellSchema::Action::PORTAL:
                return actionFactory.portal(ctx, std::get<schema::CellSchema::PortalData>(data).target);
            case schema::CellSchema::Action::null:
                return std::nullopt;
        }
    }

    schema::CellSchema::Action ActionMapper::to(const ecs::CellAction &action) {
        if (util::cast<const ecs::ActionAddScore>(&action)) {
            return schema::CellSchema::Action::ADD_SCORE;
        }

        return schema::CellSchema::Action::null;
    }
} // mapper