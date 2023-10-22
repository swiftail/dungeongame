
#include "repeats.h"

namespace game::tween::timeline {
    Repeats::Repeats(bool isInfinite, uint64_t count) :
            _isInfinite(isInfinite),
            _count(count) {}

    Repeats &Repeats::once() {
        static Repeats instance(false, 1);
        return instance;
    }

    Repeats &Repeats::infinite() {
        static Repeats instance(true, 0);
        return instance;
    }

    Repeats *Repeats::of(uint64_t count) {
        assert((void("Count should be positive"), count > 0));
        return new Repeats(false, count);
    }

    bool Repeats::isInfinite() const {
        return _isInfinite;
    }

    uint64_t Repeats::count() const {
        return _count;
    }
} // tween