
#include "level_schema.h"

namespace game::ser::schema {
    LevelSchema::LevelSchema(sf::Vector2u size, sf::Vector2u start, sf::Vector2u finish,
                             std::vector<std::vector<CellSchema>> cells) :
            _size(size),
            _start(start),
            _finish(finish),
            _cells(std::move(cells)) {}

    void LevelSchema::readFrom(buffer::ReadBuffer &buf) {
        using namespace buffer::readers;
        _size = readPrimitive<sf::Vector2u>(buf);
        _start = readPrimitive<sf::Vector2u>(buf);
        _finish = readPrimitive<sf::Vector2u>(buf);

        _cells.clear();
        for (size_t y = 0; y < _size.y; y++) {
            std::vector<CellSchema> _row;
            _row.reserve(_size.x);
            for (size_t x = 0; x < _size.x; x++) {
                _row.push_back(readSchema<CellSchema>(buf));
            }
            _cells.push_back(_row);
        }
    }

    void LevelSchema::writeTo(buffer::WriteBuffer &buf) const {
        using namespace buffer::writers;
        writePrimitive(buf, _size);
        writePrimitive(buf, _start);
        writePrimitive(buf, _finish);

        for (const auto &row: _cells) {
            for (const auto &cell: row) {
                writeSchema(buf, cell);
            }
        }
    }

    const sf::Vector2u &LevelSchema::size() const {
        return _size;
    }

    const sf::Vector2u &LevelSchema::start() const {
        return _start;
    }

    const sf::Vector2u &LevelSchema::finish() const {
        return _finish;
    }

    const std::vector<std::vector<CellSchema>> &LevelSchema::cells() const {
        return _cells;
    }
} // schema