#include "Group.h"

namespace artem { namespace graphics {

    Group::Group(const maths::Matrix4 transform)
        : transformationMatrix_(transform)
    {

    }

    Group::~Group()
    {
    }

    void Group::Submit(BatchRenderer* renderer) const 
    {
        renderer->PushMatrix(transformationMatrix_);

        for (const auto& sprite : sprites_)
            sprite->Submit(renderer);

        renderer->PopMatrix();
    }

    void Group::Add(Sprite* sprite)
    {
        sprites_.push_back(sprite);
    }

} }