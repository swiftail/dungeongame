
#include "field.h"

#include <iostream>

namespace game::ecs {
    Field::Field(const sf::Vector2u &size, const sf::Vector2u &start, const sf::Vector2u &finish) {
        assert((void("Size x should be > 3"), size.x > 3));
        assert((void("Size y should be > 3"), size.y > 3));
        assert((void("Size x should be < 100"), size.x < 100));
        assert((void("Size y should be < 100"), size.y < 100));
        assert((void("Start should be in range of field"), start.x < size.x && start.y < size.y));
        assert((void("Finish should be in range of field"), finish.x < size.x && finish.y < size.y));

        _size = size;
        _start = start;
        _finish = finish;

        _cells = new Cell **[size.x] {};
        for (size_t x = 0; x < size.x; x++) {
            _cells[x] = new Cell *[size.y] {};
            for (size_t y = 0; y < size.y; y++) {
                _cells[x][y] = new Cell();
            }
        }

    }

    Field::~Field() {
        freeCells();
    }

    const sf::Vector2u &Field::size() const {
        return _size;
    }

    const sf::Vector2u &Field::start() const {
        return _start;
    }

    const sf::Vector2u &Field::finish() const {
        return _finish;
    }

    Field::Field(const Field &other) {
        *this = other;
    }

    Field &Field::operator=(const Field &other) {
        if (this != &other) {
            freeCells();

            _size = other._size;
            _start = other._start;
            _finish = other._finish;

            _cells = new Cell **[_size.x]{};
            for (size_t x = 0; x < _size.x; x++) {
                _cells[x] = new Cell *[_size.y]{};
                for (size_t y = 0; y < _size.y; y++) {
                    _cells[x][y] = new Cell(*other._cells[x][y]);
                }
            }
        }
        return *this;
    }

    Field::Field(Field &&other) {
        *this = std::move(other);
    }

    Field &Field::operator=(Field &&other) {
        if (this != &other) {
            freeCells();

            _size = other._size;
            _start = other._start;
            _finish = other._finish;
            _cells = std::exchange(other._cells, nullptr);
        }
        return *this;
    }

    void Field::freeCells() {
        if (_cells == nullptr) {
            return;
        }
        for (size_t x = 0; x < _size.x; x++) {
            for (size_t y = 0; y < _size.y; y++) {
                delete _cells[x][y];
            }
            delete[] _cells[x];
        }
        delete[] _cells;
    }
} // ecs