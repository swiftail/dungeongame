
#include "movement_system.h"

#include <game/src/util/type_util.h>
#include "game/src/util/math.h"

#include <set>

namespace game::ecs {
    void MovementSystem::update(core::context::UpdateContext &ctx, Entities &entities, Field &field) {
        for (const auto &item: entities.getEntities()) {
            auto hasPosition = util::cast<entity::trait::HasPosition>(item.get());
            auto movable = util::cast<entity::trait::Movable>(item.get());

            if (hasPosition && movable) {
                auto &position = hasPosition->position();

                std::set<std::pair<uint32_t, uint32_t>> visitedPositions;
                visitedPositions.insert({position.get().x, position.get().y});

                while (true) {
                    auto newPosition = movable->targetPosition();

                    if (game::util::math::transform<int>(position.get()) == movable->targetPosition()) {
                        break;
                    }
                    if (visitedPositions.contains({newPosition.x, newPosition.y})) {
                        break;
                    }
                    visitedPositions.insert({newPosition.x, newPosition.y});
                    if (field.isValidCoords(newPosition)) {
                        auto &cell = field.getCell(newPosition);
                        if (cell.type() != Cell::Type::WALL) {
                            position.set(newPosition);
                            if (const auto &action = cell.action()) {
                                const auto result = action.value().get().activate(*item);

                                if (result == CellAction::ActionResult::REMOVE) {
                                    cell.removeAction();
                                }
                            }
                            if (movable->targetPosition() != game::util::math::transform<int>(position.get())) {
                                continue;
                            }
                        }
                    }
                    break;
                }
                movable->setTargetPosition(game::util::math::transform<int>(position.get()));
            }
        }
    }
} // ecs