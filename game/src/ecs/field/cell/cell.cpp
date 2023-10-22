
#include "cell.h"

namespace game::ecs {
    const Cell::Type &Cell::type() const {
        return _type;
    }

    std::optional<std::reference_wrapper<const CellAction>> Cell::action() const {
        if (_action.has_value()) {
            return *_action.value();
        } else {
            return std::nullopt;
        }
    }

    void Cell::setAction(const std::shared_ptr<CellAction> &action) {
        _action = std::make_optional<std::shared_ptr<CellAction>>(action);
    }

    void Cell::removeAction() {
        _action = std::nullopt;
    }

    void Cell::setType(Cell::Type type) {
        _type = type;
    }

    resource::texture::TextureKey Cell::textureKey() const {
        return _textureKey;
    }

    Cell::Cell(Cell::Type type, resource::texture::TextureKey textureKey) :
            _type(type),
            _action(std::nullopt),
            _textureKey(textureKey) {}

    Cell::Cell() : Cell(Type::EMPTY, resource::texture::TextureKey::CELL_FLOOR) {}
} // ecs