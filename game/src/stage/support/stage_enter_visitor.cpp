
#include "stage_enter_visitor.h"
#include "game/src/stage/stage_variant.h"

namespace game::stage::support {
    struct EnterVisitor {
        core::context::InitializeContext &ctx;
        const stage::StageData &data;

        void operator()(loading::StageLoading &stage) {
            stage.enter(ctx, dynamic_cast<const loading::LoadingData &>(data));
        }

        void operator()(menu::StageMenu &stage) {
            stage.enter(ctx, dynamic_cast<const menu::MenuData &>(data));
        }

        void operator()(world::StageWorld &stage) {
            stage.enter(ctx, dynamic_cast<const world::WorldData &>(data));
        }

        void operator()(game_over::StageGameOver& stage) {
            stage.enter(ctx, dynamic_cast<const game_over::GameOverData &>(data));
        }
    };

    void StageEnterVisitor::visit(
            core::context::InitializeContext &ctx,
            variant::StageVariant stage,
            const StageData &data
    ) {
        std::visit(EnterVisitor{ctx, data}, stage);

        return;
    }

} // support