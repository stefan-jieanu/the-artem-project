#include "Camera.h"

namespace artem { namespace graphics {

    Camera::Camera(const Vector2& focusPosition, float zoom, const Vector2& windowDimensions) 
        : focusPosition_(focusPosition), zoom_(zoom), windowDimensions_(windowDimensions)
    {

    }

    Camera::~Camera()
    {
    }

    void Camera::ComputeProjectionMatrix()
    {
        float left = focusPosition_.x - windowDimensions_.x / 2.0f; 
        float right = focusPosition_.x + windowDimensions_.x / 2.0f; 
        float top = focusPosition_.y - windowDimensions_.y / 2.0f; 
        float bottom = focusPosition_.y + windowDimensions_.y / 2.0f; 

        Matrix4 orthoMatrix = Matrix4::Orthographic(left, right, bottom, top, 0.1f, 100.0f);
        Matrix4 zoomMatrix = Matrix4::Scale(Vector3(1, 1, zoom_));

        ortographicsMatrix_ = orthoMatrix; //* zoomMatrix;
    }

} }