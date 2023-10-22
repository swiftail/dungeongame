
#ifndef GAME_ACTION_SPIKE_H
#define GAME_ACTION_SPIKE_H

#include <memory>
#include "game/src/ecs/field/cell/action/cell_action.h"
#include "SFML/Audio/Sound.hpp"

namespace game::ecs::impl::action {

    class ActionSpike  : public CellAction {
    private:
        std::unique_ptr<sf::Sound> _sound;

    public:
        ActionSpike(ActionSpike const &) = delete;

        ActionSpike() = delete;

        ActionSpike &operator=(ActionSpike const &) = delete;

        ActionSpike(
                std::unique_ptr<sf::Sound> sound
        );

        resource::texture::TextureKey textureKey() const override;

        ActionResult activate(entity::Entity &entity) const override;

        bool isObstacle() const override;
    };

} // action

#endif //GAME_ACTION_SPIKE_H
