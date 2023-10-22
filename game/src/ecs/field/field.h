
#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <cassert>
#include "cell/cell.h"
#include "SFML/System/Vector2.hpp"

namespace game::ecs {

    class Field {
    private:
        Cell ***_cells = nullptr;
        sf::Vector2u _size;
        sf::Vector2u _start;
        sf::Vector2u _finish;

        void freeCells();

    public:
        Field() = default;

        Field(
                const sf::Vector2u &size,
                const sf::Vector2u &start,
                const sf::Vector2u &finish
        );

        // Copy
        Field(Field const &other);

        Field &operator=(Field const &other);

        // Move
        Field(Field &&other);

        Field &operator=(Field &&other);

        ~Field();

        const sf::Vector2u &size() const;

        const sf::Vector2u &start() const;

        const sf::Vector2u &finish() const;

        template<typename N>
        Cell &getCell(const sf::Vector2<N> &coords) const;

        template<typename N>
        bool isValidCoords(const sf::Vector2<N> &coords) const;
    };

    template<typename N>
    Cell &Field::getCell(const sf::Vector2<N> &coords) const {
        assert((void("Coords should be in range of field"), isValidCoords(coords)));

        return *_cells[coords.x][coords.y];
    }

    template<typename N>
    bool Field::isValidCoords(const sf::Vector2<N> &coords) const {
        return coords.x >= 0 && coords.x < _size.x
               && coords.y >= 0 && coords.y < _size.y;
    }

} // ecs

#endif //GAME_FIELD_H
