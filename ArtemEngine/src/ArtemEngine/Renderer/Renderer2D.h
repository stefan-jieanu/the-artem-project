#pragma once

#include "OrthographicCamera.h"
#include "Color.h"
#include "Texture.h"

namespace ArtemEngine {

	class Renderer2D
	{
	public:
		static void Init();
		static void Terminate();

		static void BeginScene(const OrthographicCamera& camera);
		static void Flush();
		static void FlushAndReset();
		static void EndScene();

		// Primitives
		static void DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Color& color, float rotation = 0.0f);
		static void DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Color& color, float rotation = 0.0f);
		static void DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Shared<Texture>& texture, float rotation = 0.0f);
		static void DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Shared<Texture>& texture, float rotation = 0.0f);

		static void DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Shared<Texture>& texture, const Color& color, float rotation = 0.0f);
		static void DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Shared<Texture>& texture, const Color& color, float rotation = 0.0f);
	};

}

