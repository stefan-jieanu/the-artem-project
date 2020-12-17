#pragma once

#include "math.h"

#define PI 3.14159265358f

namespace artem { namespace maths {

    inline float toRadians(float degrees)
    {
        return (float)(degrees * (PI / 180.0f));
    }

} }