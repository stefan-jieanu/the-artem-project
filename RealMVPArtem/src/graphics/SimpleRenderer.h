#pragma once

#include <deque>
#include "Renderer.h"

namespace artem { namespace graphics {

    class SimpleRenderer : public Renderer
    {
    private:
        std::deque<const Renderable2d*> renderQueue_;
    public:
        void Submit(const Renderable2d* rend) override;
        void Flush() override;
    };

} }