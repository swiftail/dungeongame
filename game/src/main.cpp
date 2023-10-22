#include <SFML/Graphics.hpp>
#include "core/game.h"
#include "stage/stage_registry.h"
#include "stage/loading/stage_loading.h"
#include "stage/menu/stage_menu.h"
#include "stage/world/stage_world.h"
#include "resource/bundle.h"
#include "game/src/stage/game_over/stage_game_over.h"
#include "game/src/fs/config/config_serializer.h"
#include "game/src/log/logger.h"
#include "game/src/log/logging_initializer.h"

int main() {
    auto keyConfig = game::fs::config::ConfigSerializer("/Users/m.besogonov/CLionProjects/game/config.txt").read();

    sf::RenderWindow window(
            sf::VideoMode({
                                  1920u,
                                  1080u
                          }),
            "The Dungeon Game"
    );
    window.setFramerateLimit(144);

    std::vector<std::unique_ptr<game::stage::Stage>> gameStages;

    gameStages.push_back(std::make_unique<game::stage::loading::StageLoading>());
    gameStages.push_back(std::make_unique<game::stage::menu::StageMenu>());
    gameStages.push_back(std::make_unique<game::stage::world::StageWorld>());
    gameStages.push_back(std::make_unique<game::stage::game_over::StageGameOver>());

    game::stage::StageRegistry stageRegistry(gameStages);

    game::Bundle resourceBundle;

    resourceBundle.loadCritical();
    resourceBundle.loadAll();

    game::log::Logger logger = game::log::LoggingInitializer().initialize();

    game::core::Game mainLoop(
            window,
            stageRegistry,
            resourceBundle,
            keyConfig,
            logger
    );

    mainLoop.run();
}
