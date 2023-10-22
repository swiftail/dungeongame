
#include "stage_menu.h"

#include "game/src/tween/tween.h"
#include "game/src/ecs/level/levels.h"
#include "game/src/graphics/text/text_render_util.h"

namespace game::stage::menu {

    StageCode::Enum StageMenu::code() const {
        return StageCode::Enum::MENU;
    }

    void StageMenu::initialize(core::context::InitializeContext &ctx) {
        _backgroundSprite.setTexture(ctx.resourceBundle().getResource(resource::ImageKey::BACKGROUND));

        _text.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _text.setCharacterSize(80);
        _text.setString("Menu");

        size_t i = 1;
        for (const auto &item: game::ecs::level::Levels::levels()) {
            _buttons.emplace_back("Level " + std::to_string(i), i - 1);
            i++;
        }

        _buttons.emplace_back("Exit", i - 1);

        for (auto &item: _buttons) {
            item.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
            item.setSize({300, 50});
        }
    }

    void StageMenu::leave(core::context::InitializeContext &ctx) {
        ctx.resourceBundle().getResource(resource::MusicKey::MENU).stop();
    }

    void StageMenu::update(core::context::UpdateContext &ctx) {
        auto backgroundSize = ctx.resourceBundle().getResource(resource::ImageKey::BACKGROUND).getSize();
        auto windowSize = ctx.window().getSize();

        auto scaleFactor = std::max(
                (float) windowSize.x / (float) backgroundSize.x,
                (float) windowSize.y / (float) backgroundSize.y
        );

        TextRenderUtil::adjustPositionCentered(_text);
        _text.setPosition((float) windowSize.x / 2, (float) windowSize.y / 2 - 100);

        size_t i = 0;
        for (auto &item: _buttons) {
            item.setCenterPosition({(float) windowSize.x / 2, (float) windowSize.y / 2 + i * (50 + 20)});
            i++;
        }

        _backgroundSprite.setScale(scaleFactor, scaleFactor);

        for (const auto &event: ctx.events()) {
            switch (event.type) {
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            _buttonCode = (_buttons.size() + _buttonCode - 1) % _buttons.size();
                            break;
                        case sf::Keyboard::Down:
                            _buttonCode = (_buttonCode + 1) % _buttons.size();
                            break;
                        case sf::Keyboard::Enter:
                            if (_buttonCode == _buttons.size() - 1) {
                                ctx.exit();
                                return;
                            }

                            ctx.switchStage<StageCode::Enum::WORLD>(std::make_unique<world::WorldData>(
                                    _buttonCode,
                                    ecs::level::Levels::levels()[_buttonCode]
                            ));
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
    }

    void StageMenu::render(core::context::RenderContext &ctx) {
        ctx.window().draw(_backgroundSprite);

        sf::RectangleShape dim;
        dim.setSize(ctx.window().getView().getSize());

        dim.setFillColor(tween::Tween::apply(
                _enterTransitionTimeline,
                _enterTransitionMapping
        ));

        ctx.window().draw(dim);

        for (auto &item: _buttons) {
            item.draw(ctx, item.code() == _buttonCode);
        }

        ctx.window().draw(_text);
    }

    void StageMenu::enter(core::context::InitializeContext &ctx, const MenuData &data) {
        ctx.resourceBundle().getResource(resource::MusicKey::MENU).play();
        _enterTransitionTimeline.start();
    }
} // game