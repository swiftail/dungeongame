
#ifndef GAME_CELL_SCHEMA_H
#define GAME_CELL_SCHEMA_H

#include "game/src/ecs/field/cell/cell.h"
#include "game/src/ser/schema/schema.h"
#include "game/src/ser/buffer/readers.h"
#include "game/src/ser/buffer/writers.h"

namespace game::ser::schema {

    class CellSchema : Schema {
    public:
        enum class Action {
            null,
            ADD_SCORE,
            SPIKE,
            PORTAL
        };

        struct PortalData {
            sf::Vector2u target;
        };

        using ActionData = std::variant<std::monostate, PortalData>;

    private:
        ecs::Cell::Type _type;
        Action _action;
        ActionData _data;
        resource::texture::TextureKey _textureKey;

    public:
        ecs::Cell::Type type() const;

        Action action() const;

        resource::texture::TextureKey textureKey() const;

        const ActionData& data() const;

        CellSchema() = default;

        CellSchema(
                ecs::Cell::Type type,
                Action action,
                resource::texture::TextureKey textureKey,
                const ActionData& data = std::monostate{}
        );

        void readFrom(buffer::ReadBuffer &buf) override;

        void writeTo(buffer::WriteBuffer &buf) const override;
    };

} // schema

#endif //GAME_CELL_SCHEMA_H
