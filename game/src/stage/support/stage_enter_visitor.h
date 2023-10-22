
#ifndef GAME_STAGE_ENTER_VISITOR_H
#define GAME_STAGE_ENTER_VISITOR_H

#include "game/src/core/context/initialize_context.h"
#include "game/src/stage/stage.h"
#include "game/src/stage/stage_data.h"
#include "game/src/stage/stage_variant.h"

namespace game::stage::support {

    class StageEnterVisitor {
    public:
        StageEnterVisitor(StageEnterVisitor const &) = delete;

        StageEnterVisitor() = delete;

        StageEnterVisitor &operator=(StageEnterVisitor const &) = delete;

        static void visit(
                core::context::InitializeContext &ctx,
                variant::StageVariant stage,
                const StageData &data
        );
    };

} // support

#endif //GAME_STAGE_ENTER_VISITOR_H
