#pragma once

#include "ArtemEngine/Input.h"

namespace ArtemEngine {

	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
	};

}