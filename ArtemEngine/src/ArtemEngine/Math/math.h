#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace ArtemEngine {

	using Vector2 = glm::vec2;
	using Vector3 = glm::vec3;
	using Vector4 = glm::vec4;
	using Matrix4 = glm::mat4x4;
}

// Overloading the operator outside ArtemEngine namespace and inside std like this
// might seem weird but is necessary because Vector2 is not a class but an "alias"
// for glm::vec2 which is typedef<2, ......etc....>
// See the following link for more information:
// https://en.cppreference.com/w/cpp/language/adl
// https://github.com/gabime/spdlog/issues/1227
namespace std {
	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Vector2& vector)
	{
		os << "Vector2(" << vector.x << ", " << vector.y << ")";
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Vector3& vector)
	{
		os << "Vector3(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Vector4& vector)
	{
		os << "Vector4(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ")";
		return os;
	}
}