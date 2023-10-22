
#include "bundle.h"

#include <functional>
#include <thread>

namespace game {
    void Bundle::loadCritical() {
        auto font = std::make_unique<sf::Font>();
        font->loadFromFile("res/font.ttf");
        font->setSmooth(false);

        _fonts[resource::FontKey::FONT] = std::move(font);

        auto loadingSound = std::make_unique<sf::SoundBuffer>();
        loadingSound->loadFromFile("res/loading.wav");

        _sounds[resource::SoundKey::LOADING] = std::move(loadingSound);

        auto transparentImage = std::make_unique<sf::Texture>();
        transparentImage->create(1, 1);

        uint8_t transparentPixels[] = {0x00, 0x00, 0x00, 0x00};
        transparentImage->update(transparentPixels);
        transparentImage->setRepeated(true);

        _images[resource::ImageKey::TRANSPARENT] = std::move(transparentImage);
    }

    bool Bundle::completed() const {
        return _completed;
    }

    float Bundle::loadProgress() const {
        return _loadProgress;
    }

    const sf::Font &Bundle::getResource(resource::FontKey key) const {
        return *_fonts.at(key);
    }

    const sf::SoundBuffer &Bundle::getResource(resource::SoundKey key) const {
        return *_sounds.at(key);
    }

    const sf::Texture &Bundle::getResource(resource::ImageKey key) const {
        return *_images.at(key);
    }

    sf::Music &Bundle::getResource(resource::MusicKey key) const {
        return *_music.at(key);
    }

    void Bundle::_loadAllTask() {
        std::initializer_list<std::function<void()>> routines = {
                [=]() {
                    auto image = std::make_unique<sf::Texture>();
                    image->loadFromFile("res/world/background.png");
                    image->setSmooth(false);
                    image->setRepeated(false);
                    _images[resource::ImageKey::BACKGROUND] = std::move(image);
                },
                [=]() {
                    auto music = std::make_unique<sf::Music>();
                    music->openFromFile("res/theme.wav");
                    music->setLoop(true);
                    _music[resource::MusicKey::THEME] = std::move(music);
                },
                [=]() {
                    auto music = std::make_unique<sf::Music>();
                    music->openFromFile("res/menu.wav");
                    music->setLoop(true);
                    _music[resource::MusicKey::MENU] = std::move(music);
                },
                [=]() {
                    auto sound = std::make_unique<sf::SoundBuffer>();
                    sound->loadFromFile("res/world/sounds/pickup.wav");
                    _sounds[resource::SoundKey::PICKUP] = std::move(sound);
                },
                [=]() {
                    auto sound = std::make_unique<sf::SoundBuffer>();
                    sound->loadFromFile("res/world/sounds/hurt.wav");
                    _sounds[resource::SoundKey::HURT] = std::move(sound);
                },
                [=]() {
                    auto sound = std::make_unique<sf::SoundBuffer>();
                    sound->loadFromFile("res/world/sounds/teleport.wav");
                    _sounds[resource::SoundKey::TELEPORT] = std::move(sound);
                },
                [=]() {
                    auto image = std::make_unique<sf::Texture>();
                    image->loadFromFile("res/world/textures/tileset.png");
                    image->setSmooth(false);
                    image->setRepeated(false);
                    _images[resource::ImageKey::SPRITE_TILES] = std::move(image);
                },
                [=]() {
                    auto image = std::make_unique<sf::Texture>();
                    image->loadFromFile("res/world/textures/char.png");
                    image->setSmooth(false);
                    image->setRepeated(false);
                    _images[resource::ImageKey::SPRITE_CHAR] = std::move(image);
                },
        };

        auto size = routines.size();
        float step = 1.0f / (float) size;

        for (const auto &routine: routines) {
            routine();
            float newProgress = _loadProgress + step;
            _loadProgress = newProgress;
        }

        _loadProgress = 1.0f;
        _completed = true;
    }

    void Bundle::loadAll() {
        std::thread loadThread = std::thread([this] { this->_loadAllTask(); });
        loadThread.detach();
    }
}
