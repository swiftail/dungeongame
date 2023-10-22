
#ifndef GAME_WORLD_H
#define GAME_WORLD_H

#include <set>
#include "game/src/ecs/entity/entity.h"
#include "system.h"
#include "entities.h"
#include "field/field.h"

namespace game::ecs {

    class World {
    private:
        std::vector<std::unique_ptr<System>> _systems;
        Entities _entities;

        std::unique_ptr<Field> _field = nullptr;

        FieldRenderContext _fieldRenderContext;

    public:

        World(std::unique_ptr<Field> field);

        Entities& entities();

        Field& field();

        void initialize(core::context::InitializeContext& ctx);

        void render(core::context::RenderContext &ctx);

        void update(core::context::UpdateContext &ctx);

        void addSystem(std::unique_ptr<System> system);

    };

} // ecs

#endif //GAME_WORLD_H
