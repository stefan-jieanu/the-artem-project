#pragma once

#include "../Sprite.h"

namespace artem { namespace graphics {

    class Group : public Sprite
    {
    private:
        std::vector<Sprite*> sprites_;
        maths::Matrix4 transformationMatrix_;
    public:
        Group(const maths::Matrix4 transform);
        ~Group();
        void Submit(BatchRenderer* renderer) const override;
        void Add(Sprite* sprite);
    };

} }