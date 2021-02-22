#include "aepch.h"
#include "OrthographicCameraController.h"

#include "ArtemEngine/Core/Input.h"

namespace ArtemEngine {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotationEnabled)
		: camera_(-aspectRatio * zoomLevel_, aspectRatio * zoomLevel_, -zoomLevel_, zoomLevel_), 
		rotationEnabled_(rotationEnabled), aspectRatio_(aspectRatio)
	{
		cameraPosition_ = camera_.GetPosition();
		cameraRotation_ = camera_.GetRotation();
	}

	OrthographicCameraController::OrthographicCameraController(float left, float right, float bottom, float top)
		: camera_(left, right, bottom, top)
	{
		cameraPosition_ = camera_.GetPosition();
		cameraRotation_ = camera_.GetRotation();
	}

	OrthographicCameraController::~OrthographicCameraController()
	{
	}

	void OrthographicCameraController::OnUpdate(DeltaTime dt)
	{
		if (Input::GetKey(KeyCode::W))
			cameraPosition_.y += cameraTranslationSpeed_ * dt;
		else if (Input::GetKey(KeyCode::S))
			cameraPosition_.y -= cameraTranslationSpeed_ * dt;
		if (Input::GetKey(KeyCode::A))
			cameraPosition_.x -= cameraTranslationSpeed_ * dt;
		else if (Input::GetKey(KeyCode::D))
			cameraPosition_.x += cameraTranslationSpeed_ * dt;

		if (rotationEnabled_)
		{
			if (Input::GetKey(KeyCode::Q))
				cameraRotation_ -= cameraRotationSpeed_ * dt;
			else if (Input::GetKey(KeyCode::E))
				cameraRotation_ += cameraRotationSpeed_ * dt;

			camera_.SetRotation(cameraRotation_);
		}

		camera_.SetPosition(cameraPosition_);

		// Set the cameraTranslationSpeed_ equal to the zoomLevel_ such that 
		// when the camera is zoomed in it moves slower, when zoom out it moves faster
		cameraTranslationSpeed_ = zoomLevel_;
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(std::bind(&OrthographicCameraController::OnMouseScrolled, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&OrthographicCameraController::OnWindowResize, this, std::placeholders::_1));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		zoomLevel_ -= e.GetYOffset() * 0.25f;
		zoomLevel_ = std::max(zoomLevel_, 0.25f);
		camera_.SetProjection(-aspectRatio_ * zoomLevel_, aspectRatio_ * zoomLevel_, -zoomLevel_, zoomLevel_);

		return false;
	}

	bool OrthographicCameraController::OnWindowResize(WindowResizeEvent& e)
	{
		aspectRatio_ = (float)e.GetWidth() / (float)e.GetHeight();
		camera_.SetProjection(-aspectRatio_ * zoomLevel_, aspectRatio_ * zoomLevel_, -zoomLevel_, zoomLevel_);

		return false;
	}
}