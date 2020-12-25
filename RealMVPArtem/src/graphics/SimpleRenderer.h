#pragma once

#include <deque>
#include "Renderer.h"

namespace artem { namespace graphics {

    class SimpleRenderer : public Renderer
    {
    private:
        std::deque<const Renderable2d*> renderQueue_;
    public:
        void submit(const Renderable2d* rend) override;
        void flush() override;
    };

} }