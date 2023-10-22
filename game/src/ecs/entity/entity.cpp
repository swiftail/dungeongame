#include "entity.h"

namespace game::ecs::entity {

    static size_t id_counter = 0;

    size_t Entity::id() const {
        return _id;
    }

    Entity::Entity() {
        _id = (id_counter++);
    }
};

