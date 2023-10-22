#include "search.h"


#include "iostream"
#include <unordered_map>
#include <unordered_set>
#include <queue>

namespace game::util::pathfinding {


    struct VertexHash {
        auto operator()(const sf::Vector2u &p) const -> size_t {
            return (p.x << 16) + p.y;
        }
    };

    struct WeightedVertex {
        sf::Vector2u v;
        size_t w;

        bool operator<(const WeightedVertex &other) const {
            return w < other.w;
        }
    };

    std::vector<sf::Vector2u> search(
            const ecs::Field &field,
            const sf::Vector2u &start,
            const sf::Vector2u &end
    ) {
        static std::vector<sf::Vector2i> variants = {
                {-1, 0},
                {1,  0},
                {0,  -1},
                {0,  1},
        };

        std::unordered_map<sf::Vector2u, size_t, VertexHash> dist;
        std::unordered_map<sf::Vector2u, sf::Vector2u, VertexHash> prev;

        std::priority_queue<WeightedVertex, std::vector<WeightedVertex>, std::less<>> q;

        q.push({start, 0});

        for (uint x = 0; x < field.size().x; x++) {
            for (uint y = 0; y < field.size().y; y++) {
                sf::Vector2u coords = {x, y};

                if (coords == start) {
                    continue;
                }

                const auto &cell = field.getCell(coords);

                if (cell.type() != ecs::Cell::Type::EMPTY) {
                    continue;
                }

                dist[coords] = std::numeric_limits<size_t>::max();
            }
        }

        dist[start] = 0;

        while (!q.empty()) {
            const auto u = q.top();
            q.pop();

            if (u.w > dist[u.v]) {
                continue;
            }

            for (const auto &item: variants) {
                sf::Vector2i newCoords = {
                        item.x + (int) u.v.x,
                        item.y + (int) u.v.y
                };

                if (!field.isValidCoords(newCoords)) {
                    continue;
                }

                sf::Vector2u v = {
                        (uint) newCoords.x,
                        (uint) newCoords.y
                };

                if (!dist.contains(v)) {
                    continue;
                }

                size_t cost = 1;
                if (field.getCell(v).action().has_value() &&
                    field.getCell(v).action()->get().isObstacle()) {
                    cost = 10000;
                }

                size_t alt = u.w + cost;
                if (alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u.v;
                    q.push({v, alt});
                }
            }
        }


        sf::Vector2u v = end;
        std::vector<sf::Vector2u> s;
        while (v != start) {
            s.push_back(v);
            v = prev[v];
        }
        s.push_back(start);
        std::reverse(std::begin(s), std::end(s));
        return s;

    }

}
