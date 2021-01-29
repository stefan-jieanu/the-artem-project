#pragma once

#include "ArtemEngine/Core/Input.h"

namespace ArtemEngine {

	class WindowsInput : public Input
	{
	protected:
		// Keyboard handling
		bool GetKeyImpl(KeyCode keycode) override;

		// Mouse handling
		bool GetMouseButtonImpl(int button) override;
	};

}