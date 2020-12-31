#pragma once

#include "../maths/maths.h"
#include "Renderable2d.h"
#include "../logging/log_gl.h"

namespace artem { namespace graphics {

    class Renderer
    {        
    protected:

        Renderer()
        {
        }
    public:
        virtual void Submit(const Renderable2d* rend) = 0;
        virtual void Flush() = 0;
    };

} }