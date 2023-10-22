
#include "world.h"

namespace game::ecs {
    World::World(std::unique_ptr<Field> field) :
            _field(std::move(field)) {}

    Entities &World::entities() {
        return _entities;
    }

    Field &World::field() {
        return *_field;
    }

    void World::initialize(core::context::InitializeContext &ctx) {
        for (const auto &system: _systems) {
            system->initialize(ctx, field());
        }
    }

    void World::render(core::context::RenderContext &ctx) {
        _fieldRenderContext.reset(ctx.window(), field());
        for (const auto &system: _systems) {
            system->render(ctx, entities(), field(), _fieldRenderContext);
        }
    }

    void World::update(core::context::UpdateContext &ctx) {
        for (const auto &system: _systems) {
            system->update(ctx, entities(), field());
        }
    }

    void World::addSystem(std::unique_ptr<System> system) {
        _systems.push_back(std::move(system));
    }
} // ecs