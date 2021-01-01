#include "Layer.h"

namespace artem { namespace graphics {

    Layer::Layer(Shader &shader)
        : shader_(shader)
    {   
    }

    Layer::~Layer()
    {
        delete renderer_;

        for (const auto& object : objects_) 
            delete object;
    }

    void Layer::Add(Sprite* sprite)
    {
        objects_.push_back(sprite);
    }

    void Layer::Render()
    {
        renderer_->Begin();
        shader_.Bind();

        for (const auto& object : objects_)
            object->Submit(renderer_);
        
        renderer_->End();
        renderer_->Flush();
        
        shader_.Unbind();
    }

} }