#include "SceneLayer.h"

namespace artem { namespace graphics {

    SceneLayer::SceneLayer(Shader &shader)
        : Layer(shader)
    {
        renderer_ = new BatchRenderer();
        camera_ = Camera(Vector2(WINDOW_WIDTH, WINDOW_HEIGHT) / 2, 1.0f, Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));

        shader_.Bind();
        shader_.SetUniformMat4f("u_Projection", camera_.GetOrthographicMatrix());
        shader_.Unbind();
    }

    SceneLayer::~SceneLayer()
    {
    }

    void SceneLayer::Render()
    {
        // This is where you can mess with shader uniforms or other things
        // before rendering.
        Layer::Render();
    }

} }