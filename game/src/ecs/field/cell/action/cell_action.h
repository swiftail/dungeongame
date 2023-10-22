
#ifndef GAME_CELL_ACTION_H
#define GAME_CELL_ACTION_H

#include "game/src/ecs/entity/entity.h"
#include "../../../../resource/resource_key.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "game/src/resource/texture/texture_key.h"

namespace game::ecs {

    class CellAction {
    public:
        enum class ActionResult {
            NONE,
            REMOVE
        };

        virtual game::resource::texture::TextureKey textureKey() const = 0;

        virtual ActionResult activate(entity::Entity &entity) const = 0;

        virtual bool isObstacle() const = 0;

        virtual ~CellAction() = default;
    };

} // ecs

#endif //GAME_CELL_ACTION_H
