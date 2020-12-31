#pragma once

#include "../BatchRenderer.h"
#include "../Sprite.h"
#include "../maths/maths.h"
#include "../Camera.h"
#include "../settings/config.h"

namespace artem { namespace graphics {

    class Layer
    {
    protected:
        BatchRenderer* renderer_;
        std::vector<Sprite*> objects_;
        Shader shader_;
        Camera camera_;

        Layer(Shader& shader);
    public:
        virtual ~Layer();

        virtual void Add(Sprite* sprite);
        virtual void Render();
    };

} }