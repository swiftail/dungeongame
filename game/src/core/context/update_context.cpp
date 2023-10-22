
#include "update_context.h"

namespace game::core::context {
    sf::Time UpdateContext::delta() const {
        return _delta;
    }

    void UpdateContext::reset(
            sf::Time &delta
    ) {
        _shouldExit = false;
        _delta = delta;

        _nextStageCode = std::nullopt;
        _nextStageData = nullptr;

        _events.clear();
    }

    std::optional<stage::StageCode::Enum> UpdateContext::nextStage() const {
        return _nextStageCode;
    }

    std::unique_ptr<stage::StageData> UpdateContext::nextStageData() {
        return std::unique_ptr<stage::StageData>(_nextStageData.release());
    }

    std::vector<sf::Event> &UpdateContext::events() {
        return _events;
    }

    UpdateContext::UpdateContext(sf::RenderWindow &window, Bundle &resourceBundle,
                                 const fs::config::KeyConfig &keyConfig, log::Logger &logger) :
            _window(window),
            _resourceBundle(resourceBundle),
            _keyConfig(keyConfig),
            _logger(logger) {}

    const Bundle &UpdateContext::resourceBundle() const {
        return _resourceBundle;
    }

    sf::RenderWindow &UpdateContext::window() const {
        return _window;
    }

    void UpdateContext::exit() {
        _shouldExit = true;
    }

    bool UpdateContext::shouldExit() const {
        return _shouldExit;
    }

    const fs::config::KeyConfig &UpdateContext::keyConfig() const {
        return _keyConfig;
    }

    log::Logger &UpdateContext::logger() const {
        return _logger;
    }
} // game