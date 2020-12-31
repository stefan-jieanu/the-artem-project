#pragma once

#include "../maths/maths.h"

namespace artem { namespace graphics {

    using namespace maths;

    class Camera
    {

    private:
        Vector2 focusPosition_;
        float zoom_;
        Vector2 windowDimensions_;
        Matrix4 ortographicsMatrix_;

        void ComputeProjectionMatrix();
    public:
        Camera();
        Camera(const Vector2& focusPosition, float zoom, const Vector2& windowDimensions);
        ~Camera();

        inline Matrix4 GetOrthographicMatrix() const { return ortographicsMatrix_; }
    };    

} }