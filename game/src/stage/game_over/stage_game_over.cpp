
#include "stage_game_over.h"
#include "game/src/graphics/text/text_render_util.h"
#include "game/src/ecs/level/levels.h"

namespace game::stage::game_over {
    StageCode::Enum StageGameOver::code() const {
        return StageCode::Enum::GAME_OVER;
    }

    void StageGameOver::initialize(core::context::InitializeContext &ctx) {
        _mainText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _mainText.setCharacterSize(64);

        _detailsText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _detailsText.setCharacterSize(24);
        _detailsText.setFillColor(sf::Color::White);

        _hintText.setFont(ctx.resourceBundle().getResource(resource::FontKey::FONT));
        _hintText.setCharacterSize(32);
        _hintText.setFillColor(sf::Color::White);
    }

    void StageGameOver::leave(core::context::InitializeContext &ctx) {

    }

    void StageGameOver::enter(core::context::InitializeContext &ctx, const GameOverData &data) {
        _data = data;

        if (data.isLost()) {
            _mainText.setFillColor(sf::Color::Red);
            _mainText.setString("game over");

            _hintText.setString("[esc] menu\t[enter] restart");
        } else {
            _mainText.setFillColor(sf::Color::Green);
            _mainText.setString("level completed");

            if (data.levelIndex() == ecs::level::Levels::levels().size() - 1) {
                _hintText.setString("[esc] menu");
            } else {
                _hintText.setString("[esc] menu\t[enter] next level");
            }
        }
        _detailsText.setString(
                "score: " + std::to_string(data.score()) + "\t\t" + "health: " + std::to_string(data.health()));
    }

    void StageGameOver::update(core::context::UpdateContext &ctx) {
        for (const auto &event: ctx.events()) {
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                    case sf::Keyboard::Enter:
                        if (_data.isLost()) {
                            ctx.switchStage<StageCode::Enum::WORLD>(std::make_unique<stage::world::WorldData>(
                                    _data.levelIndex(),
                                    ecs::level::Levels::levels()[_data.levelIndex()]
                            ));
                        } else if (_data.levelIndex() != ecs::level::Levels::levels().size() - 1) {
                            ctx.switchStage<StageCode::Enum::WORLD>(std::make_unique<stage::world::WorldData>(
                                    _data.levelIndex() + 1,
                                    ecs::level::Levels::levels()[_data.levelIndex() + 1]
                            ));
                        }
                        break;
                    case sf::Keyboard::Escape:
                        ctx.switchStage<StageCode::Enum::MENU>(std::make_unique<stage::menu::MenuData>());
                        break;
                    default:
                        break;
                }
            }
        }
    }

    void StageGameOver::render(core::context::RenderContext &ctx) {
        TextRenderUtil::adjustPositionCentered(_mainText);
        _mainText.setPosition(
                (float) ctx.window().getSize().x / 2,
                (float) ctx.window().getSize().y / 2 - 64
        );

        TextRenderUtil::adjustPositionCentered(_detailsText);
        _detailsText.setPosition(
                (float) ctx.window().getSize().x / 2,
                (float) ctx.window().getSize().y / 2 - 64 + _mainText.getLocalBounds().height + 8
        );

        TextRenderUtil::adjustPositionCentered(_hintText);
        _hintText.setPosition(
                (float) ctx.window().getSize().x / 2,
                (float) ctx.window().getSize().y / 2 + _mainText.getLocalBounds().height + 8 +
                _detailsText.getLocalBounds().height + 64
        );

        ctx.window().draw(_mainText);
        ctx.window().draw(_detailsText);
        ctx.window().draw(_hintText);
    }
} // stage