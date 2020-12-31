#pragma once

#include "Layer.h"

namespace artem { namespace graphics {

    class SceneLayer : public Layer
    {
    public:
        SceneLayer(Shader& shader);
        ~SceneLayer();

        void Render();
    };

} }