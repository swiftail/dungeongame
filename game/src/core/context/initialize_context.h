
#ifndef GAME_INITIALIZE_CONTEXT_H
#define GAME_INITIALIZE_CONTEXT_H

#include <utility>

#include <game/src/resource/bundle.h>
#include "game/src/log/logger.h"

namespace game::core::context {

    class InitializeContext {
    private:
        const Bundle &_resourceBundle;
        log::Logger &_logger;
    public:
        InitializeContext(const Bundle &resourceBundle, log::Logger &logger);

        const Bundle &resourceBundle() const;

        log::Logger &logger() const;
    };

} // game

#endif //GAME_INITIALIZE_CONTEXT_H
