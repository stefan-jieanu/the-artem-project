#include "UILayer.h"

namespace artem { namespace graphics {

    UILayer::UILayer(Shader &shader)
        : Layer(shader)
    {
        renderer_ = new BatchRenderer();
        camera_ = Camera(Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2, 1.0f, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));

        shader_.Bind();
        shader_.SetUniformMat4f("u_Projection", camera_.GetOrthographicMatrix());
        shader_.Unbind();
    }

    UILayer::~UILayer()
    {
    }

} }