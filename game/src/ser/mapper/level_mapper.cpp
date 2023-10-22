
#include "level_mapper.h"

namespace game::ser::mapper {
    std::unique_ptr<game::ecs::World>
    LevelMapper::from(const core::context::InitializeContext &ctx, const ecs::ActionFactory &actionFactory,
                      const schema::LevelSchema &schema) {
        auto field = std::make_unique<game::ecs::Field>(
                schema.size(),
                schema.start(),
                schema.finish()
        );
        for (size_t y = 0; y < schema.size().y; y++) {
            for (size_t x = 0; x < schema.size().x; x++) {
                auto &cellSchema = schema.cells().at(x).at(y);
                auto &cell = field->getCell(sf::Vector2u(x, y));

                cell = ecs::Cell(
                        cellSchema.type(),
                        cellSchema.textureKey()
                );

                if (const auto& action = ActionMapper::from(ctx, actionFactory, cellSchema.action(), cellSchema.data())) {
                    cell.setAction(action.value());
                }
            }
        }

        return std::make_unique<game::ecs::World>(std::move(field));
    }
} // mapper