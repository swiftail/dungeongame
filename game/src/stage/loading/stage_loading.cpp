#include "stage_loading.h"
#include "game/src/ecs/level/levels.h"

#include <string>
#include <string_view>

#include <game/src/graphics/text/text_render_util.h>
#include <game/src/tween/tween.h>

namespace game::stage::loading {
    StageCode::Enum StageLoading::code() const {
        return StageCode::Enum::LOADING;
    }

    void StageLoading::initialize(core::context::InitializeContext &ctx) {
        _loadingScreenTimeline.start();

        _mainText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _mainText.setString("THE DUNGEON GAME");
        _mainText.setCharacterSize(100);
        _mainText.setStyle(sf::Text::Bold);

        _hintText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _hintText.setString("Press any key to continue");
        _hintText.setCharacterSize(20);

        _loadingText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _loadingText.setCharacterSize(20);

        _loadingBar.setSize({0, 10});

        _sound.setBuffer(ctx.resourceBundle().getResource(resource::SoundKey::LOADING));
        _sound.play();
    }

    void StageLoading::enter(core::context::InitializeContext &ctx, const LoadingData &data) {

    }

    void StageLoading::leave(core::context::InitializeContext &ctx) {

    }

    void StageLoading::update(core::context::UpdateContext &ctx) {
        for (const auto &event: ctx.events()) {
            switch (event.type) {
                case sf::Event::KeyPressed: {
                    if (_hintTimeline.isStarted() && !_menuTransitionTimeline.isStarted()) {
                        _menuTransitionTimeline.start();
                    }
                }
                default:
                    break;
            }
        }

        if (_loadingScreenTimeline.isEnded() && ctx.resourceBundle().completed() && !_hintTimeline.isStarted()) {
            _hintTimeline.start();
        }

        float loadPercent = ctx.resourceBundle().loadProgress();
        std::string progressText = std::to_string((int32_t) (loadPercent * 100)) + "%";
        _loadingText.setString(progressText);
        _loadingBar.setSize({loadingBarFullWidth * loadPercent, 10});

        if (_menuTransitionTimeline.isEnded()) {
            ctx.switchStage<StageCode::Enum::MENU>(
                    std::move(std::make_unique<menu::MenuData>(
                    ))
            );
        }
    }

    void StageLoading::render(core::context::RenderContext &ctx) {
        bool loadingScreenTimelineEnded = _loadingScreenTimeline.isEnded();
        bool menuTransitionTimelineStarted = _menuTransitionTimeline.isStarted();
        bool hintTimelineStarted = _hintTimeline.isStarted();

        sf::Color windowColor = loadingScreenTimelineEnded ? sf::Color::Black : sf::Color::White;
        sf::Color textColor = tween::Tween::apply(_loadingScreenTimeline, _loadingScreenMapping);

        ctx.window().clear(windowColor);

        if (menuTransitionTimelineStarted) {
            float transparencyFactor = tween::Tween::apply(_menuTransitionTimeline, _menuTransitionTransparency);
            textColor.a = 255.0 * (1.0 - transparencyFactor);
        }

        _mainText.setFillColor(textColor);
        _loadingText.setFillColor(textColor);
        _loadingBar.setFillColor(textColor);

        TextRenderUtil::adjustPositionCentered(_mainText);
        _mainText.setPosition(
                (float) ctx.window().getSize().x / 2,
                (float) ctx.window().getSize().y / 2
        );

        ctx.window().draw(_mainText);

        TextRenderUtil::adjustPositionCentered(_loadingText);
        _loadingText.setPosition(
                ctx.window().getSize().x / 2 + loadingBarFullWidth / 2 + loadingTextFullWidth / 2,
                ctx.window().getSize().y / 2 + _mainText.getLocalBounds().height / 2 + 30
        );
        ctx.window().draw(_loadingText);

        _loadingBar.setPosition(
                ctx.window().getSize().x / 2 - loadingBarFullWidth / 2 - loadingTextFullWidth / 2,
                ctx.window().getSize().y / 2 + _mainText.getLocalBounds().height / 2 + 30 - _loadingBar.getSize().y / 2
        );

        ctx.window().draw(_loadingText);
        ctx.window().draw(_loadingBar);

        if (hintTimelineStarted && !menuTransitionTimelineStarted) {
            float textPosition = tween::Tween::apply(
                    _hintTimeline,
                    _hintTextPositionMapping,
                    tween::timeline::Repeats::infinite(),
                    tween::timeline::Alternation::ALTERNATE
            );
            _hintText.setFillColor(tween::Tween::apply(
                    _hintTimeline,
                    _hintTextColorMapping,
                    tween::timeline::Repeats::infinite(),
                    tween::timeline::Alternation::ALTERNATE
            ));

            TextRenderUtil::adjustPositionCentered(_hintText);
            _hintText.setPosition(
                    (float) ctx.window().getSize().x / 2,
                    ctx.window().getSize().y - 100 + textPosition
            );

            ctx.window().draw(_hintText);
        }
    }
}