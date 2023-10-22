
#include "initialize_context.h"

namespace game::core::context {
    InitializeContext::InitializeContext(const Bundle& resourceBundle, log::Logger &logger)
            : _resourceBundle(resourceBundle), _logger(logger) {}

    const Bundle& InitializeContext::resourceBundle() const {
        return _resourceBundle;
    }

    log::Logger &InitializeContext::logger() const {
        return _logger;
    }
} // game