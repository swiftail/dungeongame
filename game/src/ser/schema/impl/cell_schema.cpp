
#include "cell_schema.h"

namespace game::ser::schema {
    ecs::Cell::Type CellSchema::type() const {
        return _type;
    }

    CellSchema::Action CellSchema::action() const {
        return _action;
    }

    resource::texture::TextureKey CellSchema::textureKey() const {
        return _textureKey;
    }

    const CellSchema::ActionData &CellSchema::data() const {
        return _data;
    }

    CellSchema::CellSchema(ecs::Cell::Type type, CellSchema::Action action, resource::texture::TextureKey textureKey,
                           const CellSchema::ActionData &data) :
            _type(type),
            _action(action),
            _textureKey(textureKey),
            _data(data) {}

    void CellSchema::readFrom(buffer::ReadBuffer &buf) {
        using namespace buffer::readers;
        _type = readPrimitive<ecs::Cell::Type>(buf);
        _action = readPrimitive<Action>(buf);

        switch (_action) {
            case Action::null:
            case Action::ADD_SCORE:
            case Action::SPIKE:
                _data = std::monostate{};
            case Action::PORTAL:
                _data = PortalData{readPrimitive<sf::Vector2u>(buf)};
                break;
        }

        _textureKey = readPrimitive<resource::texture::TextureKey>(buf);
    }

    void CellSchema::writeTo(buffer::WriteBuffer &buf) const {
        using namespace buffer::writers;
        writePrimitive(buf, _type);
        writePrimitive(buf, _action);

        switch (_action) {
            case Action::null:
            case Action::ADD_SCORE:
            case Action::SPIKE:
                break;
            case Action::PORTAL:
                writePrimitive(buf, std::get<PortalData>(_data).target);
                break;
        }

        writePrimitive(buf, _textureKey);
    }
} // schema