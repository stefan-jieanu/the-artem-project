#pragma once

#include "ArtemEngine/Renderer/OrthographicCamera.h"
#include "ArtemEngine/Core/DeltaTime.h"

#include "ArtemEngine/Events/ApplicationEvent.h"
#include "ArtemEngine/Events/MouseEvent.h"

namespace ArtemEngine {

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotationEnabled = false);
		~OrthographicCameraController();

		void OnUpdate(DeltaTime dt);
		void OnEvent(Event& e);

		inline const OrthographicCamera& GetCamera() const { return camera_; }
	protected:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		float aspectRatio_;
		float zoomLevel_ = 1.0f;
		bool rotationEnabled_;

		Math::Vector3 cameraPosition_;
		float cameraRotation_;

		float cameraTranslationSpeed_ = 1.0f;
		float cameraRotationSpeed_ = 180.0f;

		OrthographicCamera camera_;
	};

}

