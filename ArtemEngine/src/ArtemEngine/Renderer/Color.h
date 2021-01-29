#pragma once

#include "ArtemEngine/Math/math.h"

namespace ArtemEngine {

	struct Color
	{
		float r, g, b, a;

		Color()
		{
			r = 0.0f;
			g = 0.0f;
			b = 0.0f;
			a = 0.0f;
		}

		Color (float r, float g, float b, float a)
			: r(r), g(g), b(b), a(a) {}

		operator Math::Vector4() const { return Math::Vector4(r, g, b, a); }

		static const Color Red;
		static const Color Green;
		static const Color Blue;
		static const Color White;
		static const Color Black;
		static const Color DarkGrey;
	};

}

