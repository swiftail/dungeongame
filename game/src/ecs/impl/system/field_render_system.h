
#ifndef GAME_FIELD_RENDER_SYSTEM_H
#define GAME_FIELD_RENDER_SYSTEM_H

#include "../../system.h"

#include <iostream>

namespace game::ecs {

    class FieldRenderSystem : public System {
    private:
        void render(
                core::context::RenderContext &ctx,
                Entities &entities,
                Field &field,
                const FieldRenderContext &fieldRenderCtx
        ) override;
    };

} // ecs

#endif //GAME_FIELD_RENDER_SYSTEM_H
