#ifndef GAME_STAGE_LOADING_H
#define GAME_STAGE_LOADING_H

#include "SFML/Audio.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/System/Time.hpp"
#include "../parametrized_stage.h"
#include "loading_data.h"
#include <game/src/tween/timeline/timeline.h>
#include <game/src/tween/mapping/tween_mapping.h>
#include <game/src/tween/mapping/stepwise/tween_mapping_stepwise.h>
#include <game/src/tween/mapping/interpolation/tween_mapping_interpolation.h>
#include <game/src/tween/mapping/interpolation/property/interpolation_properties.h>

namespace game::stage::loading {
    class StageLoading : public ParametrizedStage<LoadingData> {
    private:
        sf::Text _mainText;
        sf::Text _hintText;

        const float loadingBarFullWidth = 200;
        const float loadingTextFullWidth = 25;
        sf::RectangleShape _loadingBar;
        sf::Text _loadingText;

        sf::Sound _sound;

        tween::timeline::Timeline _loadingScreenTimeline = sf::seconds(2);
        tween::mapping::stepwise::TweenMappingStepwise<sf::Color> _loadingScreenMapping = tween::mapping::stepwise::TweenMappingStepwise<sf::Color>(
                sf::Color::White,
                std::initializer_list<std::pair<size_t, sf::Color>>{
                        std::make_pair(375, sf::Color(255 / 3 * 2, 255 / 3 * 2, 255 / 3 * 2)),
                        std::make_pair(375 * 2, sf::Color(255 / 3 * 1, 255 / 3 * 1, 255 / 3 * 1)),
                        std::make_pair(375 * 3, sf::Color(255 / 3 * 0, 255 / 3 * 0, 255 / 3 * 0)),
                        std::make_pair(2000, sf::Color(255, 255, 255)),
                }
        );

        tween::timeline::Timeline _hintTimeline = sf::seconds(0.75);
        tween::mapping::interpolation::TweenMappingInterpolation<float> _hintTextPositionMapping = tween::mapping::interpolation::TweenMappingInterpolation<float>(
                0,
                -10,
                tween::mapping::interpolation::InterpolationProperties::numeric<float>(),
                tween::mapping::interpolation::TimingFunction::easeOut()
        );
        tween::mapping::interpolation::TweenMappingInterpolation<sf::Color> _hintTextColorMapping = tween::mapping::interpolation::TweenMappingInterpolation<sf::Color>(
                sf::Color::Black,
                sf::Color::White,
                tween::mapping::interpolation::InterpolationProperties::color(),
                tween::mapping::interpolation::TimingFunction::easeOut()
        );

        tween::timeline::Timeline _menuTransitionTimeline = sf::seconds(1);
        tween::mapping::interpolation::TweenMappingInterpolation<float> _menuTransitionTransparency = tween::mapping::interpolation::TweenMappingInterpolation<float>(
                0,
                1,
                tween::mapping::interpolation::InterpolationProperties::numeric<float>(),
                tween::mapping::interpolation::TimingFunction::easeOut()
        );

    public:
        StageLoading() = default;

        StageLoading(StageLoading const &) = delete;

        StageLoading &operator=(StageLoading const &) = delete;

        StageCode::Enum code() const override;

        void initialize(core::context::InitializeContext& ctx) override;

        void leave(core::context::InitializeContext& ctx) override;

        void enter(core::context::InitializeContext &ctx, const LoadingData &data) override;

        void update(core::context::UpdateContext &ctx) override;

        void render(core::context::RenderContext &ctx) override;
    };
}

#endif //GAME_STAGE_LOADING_H
