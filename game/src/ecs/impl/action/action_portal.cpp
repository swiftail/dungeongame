
#include "action_portal.h"
#include "game/src/util/type_util.h"
#include "game/src/util/math.h"

namespace game::ecs::impl::action {
    ActionPortal::ActionPortal(
            std::unique_ptr<sf::Sound> sound,
            const sf::Vector2u &targetPosition
    ) :
            _sound(std::move(sound)),
            _targetPosition(targetPosition) {}

    resource::texture::TextureKey ActionPortal::textureKey() const {
        return resource::texture::TextureKey::ACTION_PORTAL;
    }

    CellAction::ActionResult ActionPortal::activate(entity::Entity &entity) const {
        if (const auto &player = util::cast<entity::trait::Movable>(&entity)) {
            _sound->play();
            player->setTargetPosition(game::util::math::transform<int>(_targetPosition));
        }
        return ActionResult::NONE;
    }

    bool ActionPortal::isObstacle() const {
        return true;
    }
} // action