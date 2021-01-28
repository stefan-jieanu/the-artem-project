#pragma once

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace ArtemEngine { namespace Math {

	using Vector2 = glm::vec2;
	using Vector3 = glm::vec3;
	using Vector4 = glm::vec4;
	using Matrix4 = glm::mat4x4;

	inline Matrix4 Translation(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		return glm::ortho(left, right, bottom, top, zNear, zFar);
	}

	inline Matrix4 Identity()
	{
		return glm::mat4x4(1.0f);
	}

} }

// Overloading the operator outside ArtemEngine namespace and inside std like this
// might seem weird but is necessary because Vector2 is not a class but an "alias"
// for glm::vec2 which is typedef<2, ......etc....>
// See the following link for more information:
// https://en.cppreference.com/w/cpp/language/adl
// https://github.com/gabime/spdlog/issues/1227
namespace std {
	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Math::Vector2& vec)
	{
		os << "Vector2(" << vec.x << ", " << vec.y << ")";
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Math::Vector3& vec)
	{
		os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ArtemEngine::Math::Vector4& vec)
	{
		os << "Vector4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
		return os;
	}
}