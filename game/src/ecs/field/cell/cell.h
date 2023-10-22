
#ifndef GAME_CELL_H
#define GAME_CELL_H

#include <optional>
#include "action/cell_action.h"
#include "game/src/resource/texture/texture_definition.h"
#include "game/src/resource/texture/texture_registry.h"

namespace game::ecs {

    class Cell {
    public:
        enum class Type {
            EMPTY,
            WALL
        };

    private:
        Type _type;
        std::optional<std::shared_ptr<CellAction>> _action;
        resource::texture::TextureKey _textureKey;
    public:
        Cell(
                Type type,
                resource::texture::TextureKey textureKey
        );

        Cell();;

        const Type &type() const;

        void setType(Type type);

        resource::texture::TextureKey textureKey() const;

        std::optional<std::reference_wrapper<const CellAction>> action() const;

        void setAction(const std::shared_ptr<CellAction> &action);

        void removeAction();
    };

} // ecs

#endif //GAME_CELL_H
