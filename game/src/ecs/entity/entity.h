
#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <cstdlib>

namespace game::ecs::entity {

    class Entity {
    private:
        size_t _id = 0;
    public:
        virtual ~Entity() = default;

        virtual bool isAlive() = 0;

        Entity();

        size_t id() const;
    };


} // ecs

#endif //GAME_ENTITY_H
