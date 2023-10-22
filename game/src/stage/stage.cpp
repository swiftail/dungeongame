
#include "stage.h"

namespace game::stage {
    void Stage::assertInitialized(core::context::InitializeContext &ctx) {
        if (_initialized) {
            return;
        }
        initialize(ctx);
        _initialized = true;
    }
}

