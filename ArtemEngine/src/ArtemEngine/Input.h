#pragma once

#include "ArtemEngine/Core.h"

namespace ArtemEngine {

	class ARTEM_ENGINE_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return sInstance_->IsKeyPressedImpl(keycode); }
		inline static bool IsMouseButtonPressed(int button) { return sInstance_->IsMouseButtonPressedImpl(button); }


	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;

	private:
		static Input* sInstance_;
	};

}