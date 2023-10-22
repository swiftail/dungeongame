
#ifndef GAME_STAGE_MENU_H
#define GAME_STAGE_MENU_H

#include "game/src/stage/parametrized_stage.h"
#include "game/src/tween/mapping/interpolation/tween_mapping_interpolation.h"
#include "game/src/tween/mapping/interpolation/property/interpolation_properties.h"
#include "game/src/tween/mapping/interpolation/function/timing_function.h"
#include "menu_data.h"
#include "game/src/ui/button.h"

namespace game::stage::menu {

    class StageMenu : public ParametrizedStage<MenuData> {
    private:
        sf::Sprite _backgroundSprite;
        sf::Text _text;
        tween::timeline::Timeline _enterTransitionTimeline = sf::seconds(1);
        tween::mapping::interpolation::TweenMappingInterpolation<sf::Color> _enterTransitionMapping = {
                sf::Color::Black,
                sf::Color(0,0,0,100),
                tween::mapping::interpolation::InterpolationProperties::color(),
                tween::mapping::interpolation::TimingFunction::easeOut()
        };
        size_t _buttonCode = 0;

        std::vector<ui::Button> _buttons;
    public:
        StageCode::Enum code() const override;

        void initialize(core::context::InitializeContext &ctx) override;

        void enter(core::context::InitializeContext &ctx, const MenuData& data) override;

        void leave(core::context::InitializeContext &ctx) override;

        void update(core::context::UpdateContext &ctx) override;

        void render(core::context::RenderContext &ctx) override;
    };

} // game

#endif //GAME_STAGE_MENU_H
