
#include "texture_registry.h"

namespace game::resource::texture {

    TextureRegistry::TextureRegistry() {
        _data[TextureKey::PLAYER] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_CHAR,
                sf::IntRect(0, 0, 16, 16)
        );
        _data[TextureKey::ENEMY_SKULL] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_CHAR,
                sf::IntRect(16, 16, 16, 16)
        );
        _data[TextureKey::ENEMY_ZOMBIE] =  std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_CHAR,
                sf::IntRect(32, 16, 16, 16)
        );
        _data[TextureKey::ENEMY_PROJECTILE] =  std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_CHAR,
                sf::IntRect(0, 16, 16, 16)
        );

        _data[TextureKey::CELL_FLOOR] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 6, 0, 16, 16)
        );

        _data[TextureKey::TRANSPARENT] = std::make_unique<TextureDefinition>(
                ImageKey::TRANSPARENT,
                sf::IntRect(0, 0, 16, 16)
        );

        _data[TextureKey::CELL_WALL_LEFT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(0, 0, 16, 16)
        );
        _data[TextureKey::CELL_WALL_RIGHT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 5, 0, 16, 16)
        );
        _data[TextureKey::CELL_WALL_TOP] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16, 0, 16, 16)
        );
        _data[TextureKey::CELL_WALL_BOTTOM] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16, 16 * 4, 16, 16)
        );

        _data[TextureKey::CELL_WALL_BOTTOM_LEFT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(0, 16 * 4, 16, 16)
        );
        _data[TextureKey::CELL_WALL_BOTTOM_RIGHT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 5, 16 * 4, 16, 16)
        );
        _data[TextureKey::CELL_WALL_TOP_LEFT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(0, 0, 16, 16)
        );
        _data[TextureKey::CELL_WALL_TOP_RIGHT] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 5, 0, 16, 16)
        );

        _data[TextureKey::CELL_TRAPDOOR] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 8, 16 * 3, 16, 16)
        );
        _data[TextureKey::CELL_LADDER] = std::make_unique<TextureDefinition>(
                ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 9, 16 * 3, 16, 16)
        );


        _data[TextureKey::ACTION_ADD_SCORE] = std::make_unique<TextureDefinition>(
                resource::ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 6, 16 * 8, 16, 16),
                TextureDefinition::Animation::SWING
        );
        _data[TextureKey::ACTION_SPIKE] = std::make_unique<TextureDefinition>(
                resource::ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 9, 16 * 6, 16, 16)
        );
        _data[TextureKey::ACTION_PORTAL] = std::make_unique<TextureDefinition>(
                resource::ImageKey::SPRITE_TILES,
                sf::IntRect(16 * 8, 16 * 6, 16, 16),
                TextureDefinition::Animation::ROTATE
        );
    }

    const TextureRegistry &TextureRegistry::instance() {
        static TextureRegistry registry;
        return registry;
    }

    const std::unique_ptr<TextureDefinition> &TextureRegistry::get(TextureKey key) const {
        return _data.at(key);
    }
} // texture