#pragma once

#include "Layer.h"

namespace artem { namespace graphics {

    class UILayer : public Layer
    {
    public:
        UILayer(Shader& shader);
        ~UILayer();
    };

} }