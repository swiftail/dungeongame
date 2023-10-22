
#include "levels.h"

namespace game {
    namespace ecs {
        namespace level {
            ser::schema::LevelSchema Levels::first() {
                sf::Vector2u size(13, 13);
                std::vector<std::vector<ser::schema::CellSchema>> cells(
                        size.y,
                        std::vector<ser::schema::CellSchema>(size.x)
                );

                uint32_t i = 0;
                for (auto &row: cells) {
                    for (auto &x: row) {
                        x = ser::schema::CellSchema(
                                ecs::Cell::Type::EMPTY,
                                i % 5 == 1 ? ser::schema::CellSchema::Action::ADD_SCORE :
                                i % 5 == 3 ? ser::schema::CellSchema::Action::SPIKE :
                                ser::schema::CellSchema::Action::null,
                                resource::texture::TextureKey::CELL_FLOOR
                        );
                        i++;
                    }

                }

                cells.at(5).at(5) = ser::schema::CellSchema(
                        ecs::Cell::Type::EMPTY,
                        ser::schema::CellSchema::Action::PORTAL,
                        resource::texture::TextureKey::CELL_FLOOR,
                        ser::schema::CellSchema::PortalData{sf::Vector2u(10, 10)}
                );

                cells.at(10).at(10) = ser::schema::CellSchema(
                        ecs::Cell::Type::EMPTY,
                        ser::schema::CellSchema::Action::PORTAL,
                        resource::texture::TextureKey::CELL_FLOOR,
                        ser::schema::CellSchema::PortalData{sf::Vector2u(5, 5)}
                );

                for (size_t x = 1; x < size.x - 1; x++) {
                    cells.at(x).at(0) = ser::schema::CellSchema(
                            ecs::Cell::Type::WALL,
                            ser::schema::CellSchema::Action::null,
                            resource::texture::TextureKey::CELL_WALL_TOP
                    );
                    cells.at(x).at(size.y - 1) = ser::schema::CellSchema(
                            ecs::Cell::Type::WALL,
                            ser::schema::CellSchema::Action::null,
                            resource::texture::TextureKey::CELL_WALL_BOTTOM
                    );
                }
                for (size_t y = 1; y < size.y - 1; y++) {
                    cells.at(0).at(y) = ser::schema::CellSchema(
                            ecs::Cell::Type::WALL,
                            ser::schema::CellSchema::Action::null,
                            resource::texture::TextureKey::CELL_WALL_LEFT
                    );
                    cells.at(size.x - 1).at(y) = ser::schema::CellSchema(
                            ecs::Cell::Type::WALL,
                            ser::schema::CellSchema::Action::null,
                            resource::texture::TextureKey::CELL_WALL_RIGHT
                    );
                }

                cells.at(0).at(0) = ser::schema::CellSchema(
                        ecs::Cell::Type::WALL,
                        ser::schema::CellSchema::Action::null,
                        resource::texture::TextureKey::CELL_WALL_TOP_LEFT
                );
                cells.at(0).at(size.y - 1) = ser::schema::CellSchema(
                        ecs::Cell::Type::WALL,
                        ser::schema::CellSchema::Action::null,
                        resource::texture::TextureKey::CELL_WALL_BOTTOM_LEFT
                );
                cells.at(size.x - 1).at(0) = ser::schema::CellSchema(
                        ecs::Cell::Type::WALL,
                        ser::schema::CellSchema::Action::null,
                        resource::texture::TextureKey::CELL_WALL_TOP_RIGHT
                );
                cells.at(size.x - 1).at(size.y - 1) = ser::schema::CellSchema(
                        ecs::Cell::Type::WALL,
                        ser::schema::CellSchema::Action::null,
                        resource::texture::TextureKey::CELL_WALL_BOTTOM_RIGHT
                );

                ser::schema::LevelSchema level(
                        size,
                        sf::Vector2u(1, 1),
                        sf::Vector2u(11, 11),
                        cells
                );

                return level;
            }

            ser::schema::LevelSchema Levels::second() {
                sf::Vector2u size(13, 13);
                std::vector<std::vector<ser::schema::CellSchema>> cells(
                        size.y,
                        std::vector<ser::schema::CellSchema>(size.x)
                );

                uint32_t i = 0;
                for (auto &row: cells) {
                    for (auto &x: row) {
                        x = ser::schema::CellSchema(
                                ecs::Cell::Type::EMPTY,
                                ser::schema::CellSchema::Action::ADD_SCORE,
                                resource::texture::TextureKey::CELL_FLOOR
                        );
                        i++;
                    }
                }

                ser::schema::LevelSchema level(
                        size,
                        sf::Vector2u(1, 1),
                        sf::Vector2u(11, 11),
                        cells
                );

                return level;
            }

            const std::vector<ser::schema::LevelSchema> &Levels::levels() {
                static std::vector<ser::schema::LevelSchema> instance = {
                        first(),
                        second()
                };
                return instance;
            }
        } // game
    } // ecs
} // Level