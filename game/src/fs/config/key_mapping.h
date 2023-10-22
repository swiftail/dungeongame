
#ifndef GAME_KEY_MAPPING_H
#define GAME_KEY_MAPPING_H

#include <map>
#include <string>
#include "SFML/Window/Keyboard.hpp"

namespace game::fs::config {

#define ADD_MAPPING(x) \
    _str2key.insert({ #x, sf::Keyboard::Key::x }); \
    _key2str.insert({ sf::Keyboard::Key::x, #x })

    class KeyMapping {
    private:
        std::map<std::string, sf::Keyboard::Key> _str2key;
        std::map<sf::Keyboard::Key, std::string> _key2str;

        KeyMapping() {
            ADD_MAPPING(A);
            ADD_MAPPING(B);
            ADD_MAPPING(C);
            ADD_MAPPING(D);
            ADD_MAPPING(E);
            ADD_MAPPING(F);
            ADD_MAPPING(G);
            ADD_MAPPING(H);
            ADD_MAPPING(I);
            ADD_MAPPING(J);
            ADD_MAPPING(K);
            ADD_MAPPING(L);
            ADD_MAPPING(M);
            ADD_MAPPING(N);
            ADD_MAPPING(O);
            ADD_MAPPING(P);
            ADD_MAPPING(Q);
            ADD_MAPPING(R);
            ADD_MAPPING(S);
            ADD_MAPPING(T);
            ADD_MAPPING(U);
            ADD_MAPPING(V);
            ADD_MAPPING(W);
            ADD_MAPPING(X);
            ADD_MAPPING(Y);
            ADD_MAPPING(Z);
            ADD_MAPPING(Num0);
            ADD_MAPPING(Num1);
            ADD_MAPPING(Num2);
            ADD_MAPPING(Num3);
            ADD_MAPPING(Num4);
            ADD_MAPPING(Num5);
            ADD_MAPPING(Num6);
            ADD_MAPPING(Num7);
            ADD_MAPPING(Num8);
            ADD_MAPPING(Num9);
            ADD_MAPPING(Escape);
            ADD_MAPPING(LControl);
            ADD_MAPPING(LShift);
            ADD_MAPPING(LAlt);
            ADD_MAPPING(LSystem);
            ADD_MAPPING(RControl);
            ADD_MAPPING(RShift);
            ADD_MAPPING(RAlt);
            ADD_MAPPING(RSystem);
            ADD_MAPPING(Menu);
            ADD_MAPPING(LBracket);
            ADD_MAPPING(RBracket);
            ADD_MAPPING(Semicolon);
            ADD_MAPPING(Comma);
            ADD_MAPPING(Period);
            ADD_MAPPING(Apostrophe);
            ADD_MAPPING(Slash);
            ADD_MAPPING(Backslash);
            ADD_MAPPING(Grave);
            ADD_MAPPING(Equal);
            ADD_MAPPING(Hyphen);
            ADD_MAPPING(Space);
            ADD_MAPPING(Enter);
            ADD_MAPPING(Backspace);
            ADD_MAPPING(Tab);
            ADD_MAPPING(PageUp);
            ADD_MAPPING(PageDown);
            ADD_MAPPING(End);
            ADD_MAPPING(Home);
            ADD_MAPPING(Insert);
            ADD_MAPPING(Delete);
            ADD_MAPPING(Add);
            ADD_MAPPING(Subtract);
            ADD_MAPPING(Multiply);
            ADD_MAPPING(Divide);
            ADD_MAPPING(Left);
            ADD_MAPPING(Right);
            ADD_MAPPING(Up);
            ADD_MAPPING(Down);
            ADD_MAPPING(Numpad0);
            ADD_MAPPING(Numpad1);
            ADD_MAPPING(Numpad2);
            ADD_MAPPING(Numpad3);
            ADD_MAPPING(Numpad4);
            ADD_MAPPING(Numpad5);
            ADD_MAPPING(Numpad6);
            ADD_MAPPING(Numpad7);
            ADD_MAPPING(Numpad8);
            ADD_MAPPING(Numpad9);
            ADD_MAPPING(F1);
            ADD_MAPPING(F2);
            ADD_MAPPING(F3);
            ADD_MAPPING(F4);
            ADD_MAPPING(F5);
            ADD_MAPPING(F6);
            ADD_MAPPING(F7);
            ADD_MAPPING(F8);
            ADD_MAPPING(F9);
            ADD_MAPPING(F10);
            ADD_MAPPING(F11);
            ADD_MAPPING(F12);
            ADD_MAPPING(F13);
            ADD_MAPPING(F14);
            ADD_MAPPING(F15);
            ADD_MAPPING(Pause);
        }

    public:
        KeyMapping(KeyMapping const &) = delete;

        KeyMapping &operator=(KeyMapping const &) = delete;

        static const KeyMapping &instance();

        std::optional<std::string_view> keyToString(sf::Keyboard::Key key) const;

        std::optional<sf::Keyboard::Key> stringToKey(const std::string &string) const;
    };

} // config

#endif //GAME_KEY_MAPPING_H
