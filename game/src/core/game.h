#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <SFML/Graphics.hpp>
#include "../stage/stage.h"
#include "../stage/stage_registry.h"
#include "../resource/bundle.h"
#include "game/src/stage/stage_data.h"
#include "game/src/log/logger.h"

#include <any>

namespace game::core {
    class Game {

    private:
        sf::RenderWindow &_window;
        stage::StageRegistry &_stageRegistry;
        game::Bundle &_resourceBundle;

        std::optional<std::reference_wrapper<stage::Stage>> _activeStage;

        sf::Clock _deltaClock;

        log::Logger &_logger;
        fs::config::KeyConfig &_keyConfig;

        context::UpdateContext _updateCtx;
        context::RenderContext _renderCtx;
        context::InitializeContext _initializeCtx;

        void switchStage(stage::Stage &newStage, const stage::StageData &data);

    public:
        Game(Game const &) = delete;

        Game() = delete;

        Game &operator=(Game const &) = delete;

        Game(
                sf::RenderWindow &window,
                stage::StageRegistry &stageRegistry,
                game::Bundle &resourceBundle,
                fs::config::KeyConfig &keyConfig,
                log::Logger &logger
        );

        void run();
    };
}

#endif //GAME_GAME_H
