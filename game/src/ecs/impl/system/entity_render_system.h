
#ifndef GAME_ENTITY_RENDER_SYSTEM_H
#define GAME_ENTITY_RENDER_SYSTEM_H

#include "../../system.h"
#include "../entity/player.h"
#include "game/src/tween/tween.h"
#include "game/src/tween/mapping/interpolation/tween_mapping_interpolation.h"
#include "game/src/tween/mapping/interpolation/function/timing_function.h"
#include "game/src/tween/mapping/interpolation/property/interpolation_properties.h"

namespace game::ecs {

    class EntityRenderSystem : public System {
    private:
        tween::mapping::interpolation::TweenMappingInterpolation<sf::Color> _damageColorMapping = {
                sf::Color::Red,
                sf::Color::White,
                tween::mapping::interpolation::InterpolationProperties::color(),
                tween::mapping::interpolation::TimingFunction::easeOut()
        };
    public:
        void render(
                core::context::RenderContext &ctx,
                Entities &entities,
                Field &field,
                const FieldRenderContext &fieldRenderCtx
        ) override;
    };

} // ecs

#endif //GAME_ENTITY_RENDER_SYSTEM_H
