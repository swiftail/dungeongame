
#ifndef GAME_REPEATS_H
#define GAME_REPEATS_H

#include <cstdint>
#include <cassert>

namespace game::tween::timeline {

    class Repeats {
    private:
        bool _isInfinite;
        uint64_t _count;

        Repeats(bool isInfinite, uint64_t count);

    public:
        Repeats(Repeats const &) = delete;

        Repeats() = delete;

        Repeats &operator=(Repeats const &) = delete;

        bool isInfinite() const;

        uint64_t count() const;

        static Repeats& once();

        static Repeats& infinite();

        static Repeats *of(uint64_t count);
    };

} // tween

#endif //GAME_REPEATS_H
