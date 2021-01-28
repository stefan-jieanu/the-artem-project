#include "aepch.h"
#include "OrthographicCamera.h"

namespace ArtemEngine {

	OrthographicCamera::OrthographicCamera()
	{
		// If no parameters are provided initialize the camera with the default OpenGL parameters.
		projectionMatrix_ = Math::Orthographic(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

		position_ = Math::Vector3(0, 0, 0);
		rotation_ = 0.0f;
		RecalculateViewMatrix();
	}

	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
	{
		projectionMatrix_ = Math::Orthographic(left, right, bottom, top, -1.0f, 1.0f);

		position_ = Math::Vector3(0, 0, 0);
		rotation_ = 0.0f;
		RecalculateViewMatrix();
	}

	OrthographicCamera::~OrthographicCamera()
	{
	}

	void OrthographicCamera::SetPosition(const Math::Vector3& position)
	{
		position_ = position;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::SetRotation(float rotation)
	{
		rotation_ = rotation;
		RecalculateViewMatrix();
	}

	void OrthographicCamera::RecalculateViewMatrix()
	{
		Math::Matrix4 transform = Math::Translate(position_) *
			Math::Rotate(Math::Radians(rotation_), Math::Vector3(0, 0, 1));

		viewMatrix_ = Math::Inverse(transform);
		projectionViewMatrix_ = projectionMatrix_ * viewMatrix_;
	}
}