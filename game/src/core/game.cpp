#include "game.h"
#include "game/src/stage/loading/loading_data.h"
#include "game/src/stage/support/stage_enter_visitor.h"

#include <utility>
#include <iostream>

namespace game::core {
    void Game::run() {
        while (_window.isOpen()) {
            sf::Time delta = _deltaClock.restart();

            _updateCtx.reset(delta);
            _renderCtx.reset(delta);

            for (auto event = sf::Event{}; _window.pollEvent(event);) {
                switch (event.type) {
                    case sf::Event::Closed: {
                        _window.close();
                        return;
                    }
                    case sf::Event::Resized: {
                        sf::FloatRect visibleArea(
                                0,
                                0,
                                (float) event.size.width,
                                (float) event.size.height
                        );
                        _window.setView(sf::View(visibleArea));
                        break;
                    }
                    default: {
                        _updateCtx.events().push_back(event);
                    }
                }
            }

            _window.clear();

            _activeStage.value().get().update(_updateCtx);
            _activeStage.value().get().render(_renderCtx);

            if (_updateCtx.shouldExit()) {
                break;
            }

            if (const auto &nextStage = _updateCtx.nextStage()) {
                auto nextStageData = _updateCtx.nextStageData();
                switchStage(
                        _stageRegistry.getStage(nextStage.value()),
                        *nextStageData
                );
            }

            _window.display();
        }
    }

    void Game::switchStage(stage::Stage &newStage, const stage::StageData &data) {
        if (_activeStage) {
            _activeStage.value().get().leave(_initializeCtx);
        }

        newStage.assertInitialized(_initializeCtx);
        stage::support::StageEnterVisitor::visit(
                _initializeCtx,
                stage::variant::cast(newStage),
                data
        );

        _activeStage = newStage;
    }

    Game::Game(
             sf::RenderWindow& window,
             stage::StageRegistry& stageRegistry,
             game::Bundle& resourceBundle,
             fs::config::KeyConfig& keyConfig,
             log::Logger& logger
    ) :
            _window(window),
            _stageRegistry(stageRegistry),
            _resourceBundle(resourceBundle),
            _keyConfig(keyConfig),
            _logger(logger),

            _updateCtx(core::context::UpdateContext(_window, _resourceBundle, keyConfig, logger)),
            _renderCtx(core::context::RenderContext(_window, _resourceBundle)),
            _initializeCtx(core::context::InitializeContext(_resourceBundle, logger)) {

        this->switchStage(
                this->_stageRegistry.getStage(stage::StageCode::Enum::LOADING),
                stage::loading::LoadingData()
        );
    }
}