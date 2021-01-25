#pragma once

#include "Event.h"

namespace ArtemEngine {

	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode_; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(int keycode)
			: keyCode_(keycode) {}

		int keyCode_;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode)
			: KeyEvent(keycode) {}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode_;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
	};

	class KeyRepeatEvent : public KeyEvent
	{
	public:
		KeyRepeatEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyRepeatEvent: " << keyCode_;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRepeat);
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode_;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}