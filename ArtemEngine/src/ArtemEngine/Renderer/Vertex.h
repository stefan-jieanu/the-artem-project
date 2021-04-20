#pragma once

#include "Shader.h"

namespace ArtemEngine
{
	class VertexData
	{
	public:
		VertexData(const ShaderLayout& layout, );
		~VertexData();

		void SetData(const std::string name, float data, int offset = 0)
		{
			
		}

		void SetData(const std::string name, Math::Vector2 data, int offset = 0)
		{

		}

		void SetData(const std::string name, Math::Vector3 data, int offset = 0)
		{

		}

		template<typename T>
		T GetData(const std::string name, int offset = 0)
		{
		}

		template<>
		float GetData<float>(const std::string name, int offset)
		{

		}

		template<>
		Math::Vector2 GetData<Math::Vector2>(const std::string name, int offset)
		{

		}

		template<>
		Math::Vector3 GetData<Math::Vector3>(const std::string name, int offset)
		{

		}
		
	private:
		float* data;
		ShaderLayout layout;
		int count;

		static float* Create(const ShaderLayout& layout, int count = 1)
		{
			return new float[layout.GetSize() * count];
		}

		static void SetData(float* vertex, const ShaderLayout& layout, const std::string& name, float data)
		{
			int location = layout.GetElementLocation(name);
			vertex[location] = data;
		}

		static void SetData(const float* vertex, const ShaderLayout* layout, const std::string& name, const Math::Vector2 data)
		{

		}

		static void SetData(const float* vertex, const ShaderLayout* layout, const std::string& name, const Math::Vector3 data)
		{

		}

		static float GetData(float* vertex, const ShaderLayout& layout, const std::string& name)
		{
			int location = layout.GetElementLocation(name);
			return vertex[location];
		}
	};


	/*template<typename...> struct Vertex;

	template<typename T1>
	struct Vertex<T1>
	{
		T1 t1;
	};

	template<typename T1, typename T2>
	struct Vertex<T1, T2>
	{
		T1 t1;
		T2 t2;
	};

	template<typename T1, typename T2, typename T3>
	struct Vertex<T1, T2, T3>
	{
		T1 t1;
		T2 t2;
		T3 t3;
	};

	template<typename T1, typename T2, typename T3, typename T4>
	struct Vertex<T1, T2, T3, T4>
	{
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
	};

	template<typename T1, typename T2, typename T3, typename T4, typename T5>
	struct Vertex<T1, T2, T3, T4, T5>
	{
		T1 t1;
		T2 t2;
		T3 t3;
		T4 t4;
		T5 t5;
	};*/

}