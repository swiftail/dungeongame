#ifndef GAME_UPDATE_CONTEXT_H
#define GAME_UPDATE_CONTEXT_H

#include <SFML/Graphics.hpp>
#include <game/src/stage/stage_code.h>
#include <game/src/resource/bundle.h>

#include <any>
#include "game/src/stage/stage_data.h"
#include "game/src/stage/support/typing.h"
#include "game/src/fs/config/key_config.h"
#include "game/src/log/logger.h"

namespace game::core::context {

    class UpdateContext {
    private:
        const fs::config::KeyConfig &_keyConfig;
        sf::RenderWindow &_window;
        sf::Time _delta;

        bool _shouldExit;

        std::optional<stage::StageCode::Enum> _nextStageCode = std::nullopt;
        std::unique_ptr<stage::StageData> _nextStageData = nullptr;

        std::vector<sf::Event> _events;
        const Bundle &_resourceBundle;

        log::Logger &_logger;

    public:
        UpdateContext(sf::RenderWindow &window, Bundle &resourceBundle, const fs::config::KeyConfig &, log::Logger &logger);

        sf::Time delta() const;

        void reset(sf::Time &delta);

        template<stage::StageCode::Enum e, typename T>
        void switchStage(std::unique_ptr<T> data);

        std::vector<sf::Event> &events();

        std::optional<stage::StageCode::Enum> nextStage() const;

        std::unique_ptr<stage::StageData> nextStageData();

        const Bundle &resourceBundle() const;

        sf::RenderWindow &window() const;

        void exit();

        bool shouldExit() const;

        const fs::config::KeyConfig &keyConfig() const;

        log::Logger &logger() const;
    };


    template<stage::StageCode::Enum e, typename T>
    void UpdateContext::switchStage(std::unique_ptr<T> data) {
        static_assert(stage::support::typing::isValidDataType<e, T>());

        _nextStageCode = e;
        _nextStageData = std::unique_ptr<stage::StageData>{dynamic_cast<stage::StageData*>(data.release())};
    }

} // game

#endif //GAME_UPDATE_CONTEXT_H
