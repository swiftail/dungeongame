
#ifndef GAME_BUNDLE_H
#define GAME_BUNDLE_H

#include <atomic>
#include "resource_key.h"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Music.hpp"

#include <SFML/Graphics.hpp>

namespace game {

    class Bundle {
    private:
        volatile bool _completed;
        volatile float _loadProgress;

        std::map<resource::FontKey, std::unique_ptr<sf::Font>> _fonts;
        std::map<resource::SoundKey, std::unique_ptr<sf::SoundBuffer>> _sounds;
        std::map<resource::ImageKey, std::unique_ptr<sf::Texture>> _images;
        std::map<resource::MusicKey, std::unique_ptr<sf::Music>> _music;

        void _loadAllTask();

    public:
        void loadCritical();

        void loadAll();

        bool completed() const;

        float loadProgress() const;

        const sf::Font &getResource(resource::FontKey key) const;

        const sf::SoundBuffer &getResource(resource::SoundKey key) const;

        const sf::Texture &getResource(resource::ImageKey key) const;

        sf::Music &getResource(resource::MusicKey key) const;
    };

}


#endif //GAME_BUNDLE_H
