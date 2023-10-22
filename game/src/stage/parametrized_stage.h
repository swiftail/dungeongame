
#ifndef GAME_PARAMETRIZED_STAGE_H
#define GAME_PARAMETRIZED_STAGE_H

#include "stage.h"

namespace game::stage {

    template<typename T>
    class ParametrizedStage : public Stage {
    public:
        virtual void enter(core::context::InitializeContext &ctx, const T &data) = 0;

        virtual ~ParametrizedStage() = default;
    };

} // stage

#endif //GAME_PARAMETRIZED_STAGE_H
