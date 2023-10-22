
#ifndef GAME_LEVEL_SCHEMA_H
#define GAME_LEVEL_SCHEMA_H

#include <cstdint>
#include <utility>
#include <vector>
#include "cell_schema.h"
#include "game/src/ser/buffer/readers.h"
#include "game/src/ser/buffer/writers.h"

namespace game::ser::schema {

    class LevelSchema : Schema {
    private:
        sf::Vector2u _size;
        sf::Vector2u _start;
        sf::Vector2u _finish;
        std::vector<std::vector<CellSchema>> _cells;
    public:
        LevelSchema(
                sf::Vector2u size,
                sf::Vector2u start,
                sf::Vector2u finish,
                std::vector<std::vector<CellSchema>> cells
        );

        void readFrom(buffer::ReadBuffer &buf) override;

        void writeTo(buffer::WriteBuffer &buf) const override;

        const sf::Vector2u &size() const;

        const sf::Vector2u &start() const;

        const sf::Vector2u &finish() const;

        const std::vector<std::vector<CellSchema>> &cells() const;
    };

} // schema

#endif //GAME_LEVEL_SCHEMA_H
