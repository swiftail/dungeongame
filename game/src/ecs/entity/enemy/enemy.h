
#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

#include "game/src/ecs/entity/entity.h"
#include "base_enemy.h"
#include "game/src/ecs/impl/entity/player.h"
#include "game/src/util/math.h"
#include "game/src/core/context/update_context.h"

namespace game::ecs::entity::enemy {

    template<typename MoveSchema, typename InteractionSchema>
    class Enemy : public BaseEnemy, public Entity {
    private:
        std::unique_ptr<MoveSchema> _moveSchema;
        std::unique_ptr<InteractionSchema> _interactionSchema;
        resource::texture::TextureKey _textureKey;
    public:
        Enemy(Enemy const &) = delete;

        Enemy() = delete;

        Enemy &operator=(Enemy const &) = delete;

        Enemy(
                std::unique_ptr<MoveSchema> moveSchema,
                std::unique_ptr<InteractionSchema> interactionSchema,
                const int32_t_restrict &health,
                const sf::Vector2u &fieldSize,
                const sf::Vector2u &start,
                resource::texture::TextureKey textureKey
        );

        void move(const Field &field) override;

        bool interact(
                game::core::context::UpdateContext &ctx,
                Entities &entities,
                Field &field
        ) override;

        bool isAlive() override;

        resource::texture::TextureKey textureKey() override;
    };

    template<typename MoveSchema, typename InteractionSchema>
    resource::texture::TextureKey Enemy<MoveSchema, InteractionSchema>::textureKey() {
        return _textureKey;
    }

    template<typename MoveSchema, typename InteractionSchema>
    Enemy<MoveSchema, InteractionSchema>::Enemy(
            std::unique_ptr<MoveSchema> moveSchema,
            std::unique_ptr<InteractionSchema> interactionSchema,
            const int32_t_restrict &health, const sf::Vector2u &fieldSize,
            const sf::Vector2u &start,
            resource::texture::TextureKey textureKey
    ) :
            _moveSchema(std::move(moveSchema)),
            _interactionSchema(std::move(interactionSchema)),
            _textureKey(textureKey),
            BaseEnemy(
                    health,
                    RestrictedVector<uint32_t>({0, 0}, {fieldSize.x - 1, fieldSize.y - 1}, start),
                    game::util::math::transform<int>(start)
            ) {}

    template<typename MoveSchema, typename InteractionSchema>
    void Enemy<MoveSchema, InteractionSchema>::move(const Field &field) {
        const auto &target = _moveSchema->_move(field, position().get());
        setTargetPosition(target);
    }

    template<typename MoveSchema, typename InteractionSchema>
    bool Enemy<MoveSchema, InteractionSchema>::interact(
            game::core::context::UpdateContext &ctx,
            Entities &entities, Field &field
    ) {
        return _interactionSchema->_interact(ctx, *this, entities, field);
    }

    template<typename MoveSchema, typename InteractionSchema>
    bool Enemy<MoveSchema, InteractionSchema>::isAlive() {
        return _health.get() > 0;
    }

} // enemy

#endif //GAME_ENEMY_H
