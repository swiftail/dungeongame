
#include "action_spike.h"
#include "game/src/util/type_util.h"
#include "game/src/ecs/impl/entity/player.h"

namespace game::ecs::impl::action {

    ActionSpike::ActionSpike(
            std::unique_ptr<sf::Sound> sound
    ) :
            _sound(std::move(sound)) {}

    resource::texture::TextureKey ActionSpike::textureKey() const {
        return resource::texture::TextureKey::ACTION_SPIKE;
    }

    CellAction::ActionResult ActionSpike::activate(entity::Entity &entity) const {
        if (const auto &hasHealth = util::cast<entity::trait::HasHealth>(&entity)) {
            _sound->play();
            hasHealth->dealDamage(1);
        }
        return ActionResult::NONE;
    }

    bool ActionSpike::isObstacle() const {
        return true;
    }

} // action