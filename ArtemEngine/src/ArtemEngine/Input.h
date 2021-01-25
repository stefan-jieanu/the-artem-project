#pragma once

#include "ArtemEngine/Core.h"
#include "KeyCode.h"

namespace ArtemEngine {

	class Input
	{
	public:
		// Keyboard handling
		inline static bool GetKey(KeyCode keycode) { return sInstance_->GetKeyImpl(keycode); }

		// Mouse button handling
		inline static bool GetMouseButton(int button) { return sInstance_->GetMouseButtonImpl(button); }

	protected:
		virtual bool GetKeyImpl(KeyCode keycode) = 0;

		virtual bool GetMouseButtonImpl(int button) = 0;

	private:
		static Input* sInstance_;
	};

	
}