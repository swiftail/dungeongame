
#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

#include "entities.h"
#include "field/field.h"
#include "render/field_render_context.h"

#include <game/src/core/context/update_context.h>
#include <game/src/core/context/render_context.h>
#include <game/src/core/context/initialize_context.h>

namespace game::ecs {

    class System {

    public:
        virtual void initialize(core::context::InitializeContext &ctx, Field& field) {
        };

        virtual void render(core::context::RenderContext &ctx, Entities &entities, Field& field, const FieldRenderContext& fieldRenderCtx) {
        };

        virtual void update(core::context::UpdateContext &ctx, Entities &entities, Field& field) {
        };

        virtual ~System() = default;
    };

} // ecs

#endif //GAME_SYSTEM_H
