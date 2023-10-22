
#ifndef GAME_INT32_T_RESTRICT_H
#define GAME_INT32_T_RESTRICT_H

#include <algorithm>

namespace game::ecs {

    class int32_t_restrict {
    private:
        int32_t _maxValue;
        int32_t _minValue;
        int32_t _value;
    public:
        int32_t_restrict(
                int32_t maxValue,
                int32_t minValue,
                int32_t initialValue
        );

        int32_t set(int32_t value);

        int32_t get() const;

        int32_t add(int32_t value);

        float ratio() const;
    };

} // ecs

#endif //GAME_INT32_T_RESTRICT_H
