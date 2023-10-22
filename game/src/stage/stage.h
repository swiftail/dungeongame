#ifndef GAME_STAGE_H
#define GAME_STAGE_H

#include "stage_code.h"
#include <game/src/core/context/update_context.h>
#include <game/src/core/context/render_context.h>
#include <game/src/core/context/initialize_context.h>

namespace game::stage {

    class Stage {
    private:
        bool _initialized = false;

    protected:
        virtual void initialize(core::context::InitializeContext &ctx) = 0;

    public:
        void assertInitialized(core::context::InitializeContext &ctx);

        virtual StageCode::Enum code() const = 0;

        virtual void leave(core::context::InitializeContext &ctx) = 0;

        virtual void update(core::context::UpdateContext &ctx) = 0;

        virtual void render(core::context::RenderContext &ctx) = 0;

        virtual ~Stage() = default;
    };
}

#endif //GAME_STAGE_H
