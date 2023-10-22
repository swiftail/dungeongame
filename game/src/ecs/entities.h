
#ifndef GAME_ENTITIES_H
#define GAME_ENTITIES_H

#include <set>
#include <map>
#include <typeindex>
#include "game/src/ecs/entity/entity.h"

#include "game/src/util/type_util.h"

#define CHECK_TYPE(T) if (util::cast<T>(entity.get())) result.insert(std::type_index(typeid(T)))

namespace game::ecs {

    class Entities {
    private:
        std::set<std::shared_ptr<entity::Entity>> _entities;
        std::map<std::type_index, std::set<std::shared_ptr<entity::Entity>>> _entitiesByType;

        void appendEntity(std::type_index typeInfo, std::shared_ptr<entity::Entity> entity) {
            if (!_entitiesByType.contains(typeInfo)) {
                _entitiesByType.insert(std::make_pair(typeInfo, std::set<std::shared_ptr<entity::Entity>>()));
            }

            _entitiesByType.at(typeInfo).insert(entity);
        }

        std::map<std::type_index, std::set<std::type_index>> typeIndexCache;

        const std::set<std::type_index>& getAllKnownTypeIndexes(std::type_index index, std::shared_ptr<entity::Entity> entity);

    public:
        template <typename T>
        requires std::is_base_of_v<entity::Entity, T>
        void addEntity(std::shared_ptr<T> entity) {
            std::type_index typeInfo = typeid(T);

            _entities.insert(entity);

            const auto& types = getAllKnownTypeIndexes(typeInfo, entity);
            for(const auto& type : types) {
                appendEntity(type, entity);
            }
        }

        const std::set<std::shared_ptr<entity::Entity>> &getEntities();

        template<typename T>
        std::vector<std::shared_ptr<T>> getEntities();

        template<typename T>
        std::optional<std::shared_ptr<T>> getEntity();
    };

    template<typename T>
    std::optional<std::shared_ptr<T>> Entities::getEntity() {
        std::type_index typeInfo(typeid(T));

        if (!_entitiesByType.contains(typeInfo)) {
            return std::nullopt;
        }

        const auto &entitites = _entitiesByType.at(typeInfo);

        if (entitites.empty()) {
            return std::nullopt;
        }

        std::shared_ptr<T> result = std::dynamic_pointer_cast<T>(*entitites.begin());
        return std::make_optional<std::shared_ptr<T>>(result);
    }

    template<typename T>
    std::vector<std::shared_ptr<T>> Entities::getEntities() {
        std::type_index typeInfo(typeid(T));

        if (!_entitiesByType.contains(typeInfo)) {
            return std::vector<std::shared_ptr<T>>();
        }

        const std::set<std::shared_ptr<entity::Entity>> &entities = _entitiesByType.at(typeInfo);
        std::vector<std::shared_ptr<T>> result;
        result.reserve(entities.size());

        std::transform(
                entities.begin(),
                entities.end(),
                std::back_inserter(result),
                [](std::shared_ptr<entity::Entity> ptr) {
                    return std::dynamic_pointer_cast<T>(ptr);
                }
        );

        return result;
    }

} // ecs

#endif //GAME_ENTITIES_H
