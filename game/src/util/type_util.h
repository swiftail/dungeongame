
#ifndef GAME_TYPE_UTIL_H
#define GAME_TYPE_UTIL_H

namespace game::util {
    template<typename Base, typename T>
    static Base* cast(T *ptr) {
        return dynamic_cast<Base *>(ptr);
    }
} // game

#endif //GAME_TYPE_UTIL_H
