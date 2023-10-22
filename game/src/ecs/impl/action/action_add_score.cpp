
#include "action_add_score.h"

#include "../../../util/type_util.h"

namespace game::ecs {
    ActionAddScore::ActionAddScore(
            std::unique_ptr<sf::Sound> sound
    ) :
            _sound(std::move(sound)) {}

    resource::texture::TextureKey ActionAddScore::textureKey() const {
        return resource::texture::TextureKey::ACTION_ADD_SCORE;
    }

    CellAction::ActionResult ActionAddScore::activate(entity::Entity &entity) const {
        if (const auto &player = util::cast<Player>(&entity)) {
            _sound->play();
            player->score().add(1);
            return ActionResult::REMOVE;
        }
        return ActionResult::NONE;
    }

    bool ActionAddScore::isObstacle() const {
        return false;
    }
} // ecs