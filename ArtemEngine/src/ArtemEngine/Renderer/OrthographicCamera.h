#pragma once

#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

	class OrthographicCamera
	{
	public:
		OrthographicCamera();
		OrthographicCamera(float left, float right, float bottom, float top);
		~OrthographicCamera();

		void SetProjection(float left, float right, float bottom, float top);
		void SetPosition(const Math::Vector3& position);
		void SetRotation(float rotation);

		inline const Math::Vector3& GetPosition() const { return position_; }
		inline const float GetRotation() const { return rotation_; }


		inline const Math::Matrix4& GetProjectionMatrix() const { return projectionMatrix_; }
		inline const Math::Matrix4& GetViewMatrix() const { return viewMatrix_; }
		inline const Math::Matrix4& GetProjectionViewMatrix() const { return projectionViewMatrix_; }
	private:
		Math::Matrix4 projectionMatrix_;
		Math::Matrix4 viewMatrix_;
		Math::Matrix4 projectionViewMatrix_;

		Math::Vector3 position_;
		float rotation_ = 0;

		void RecalculateViewMatrix();
	};

}

