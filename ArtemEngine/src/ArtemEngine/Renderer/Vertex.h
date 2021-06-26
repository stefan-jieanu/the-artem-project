#pragma once

#include "Shader.h"

namespace ArtemEngine
{
	class VertexData
	{
	public:
		VertexData(const ShaderLayout& layout, int count = 1)
			: layout_(layout), count_(count)
		{
			data_  = new float[layout.GetSize() * (uint32_t)count];
		}

		~VertexData()
		{
			delete[] data_;
		}

		// Methods to set the data in the vertex[]
		void SetData(const std::string name, float data, int offset = 0)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			data_[location + (count_ - 1) * offset] = data;
		}

		void SetData(const std::string name, Math::Vector2 data, int offset = 0)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			data_[location + (count_ - 1) * offset] = data.x;
			data_[location + 1 + (count_ - 1) * offset] = data.y;
		}

		void SetData(const std::string name, Math::Vector3 data, int offset = 0)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			data_[location + (count_ - 1) * offset] = data.x;
			data_[location + 1 + (count_ - 1) * offset] = data.y;
			data_[location + 2 + (count_ - 1) * offset] = data.z;
		}

		void SetData(const std::string name, Math::Vector4 data, int offset = 0)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			data_[location + (count_ - 1) * offset] = data.x;
			data_[location + 1 + (count_ - 1) * offset] = data.y;
			data_[location + 2 + (count_ - 1) * offset] = data.z;
			data_[location + 3 + (count_ - 1) * offset] = data.w;
		}

		// Methods to get the data in the vertex[]
		float* GetData()
		{
			return data_;
		}

		template<typename T>
		T GetData(const std::string name, int offset = 0)
		{
		}

		template<>
		float GetData<float>(const std::string name, int offset)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			return data_[location + (count_ - 1) * offset];
		}

		template<>
		Math::Vector2 GetData<Math::Vector2>(const std::string name, int offset)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			return Math::Vector2(data_[location + (count_ - 1) * offset], data_[location + 1 + (count_ - 1) * offset]);
		}

		template<>
		Math::Vector3 GetData<Math::Vector3>(const std::string name, int offset)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			return Math::Vector3(data_[location + (count_ - 1) * offset], data_[location + 1 + (count_ - 1) * offset], data_[location + 2 + (count_ - 1) * offset]);
		}

		template<>
		Math::Vector4 GetData<Math::Vector4>(const std::string name, int offset)
		{
			LOG_CORE_ASSERT(!(offset > count_ - 1), "Vertex index is greater than total number of vertices");

			uint32_t location = layout_.GetElementLocation(name);
			return Math::Vector4(data_[location + (count_ - 1) * offset], data_[location + 1 + (count_ - 1) * offset],
				data_[location + 2 + (count_ - 1) * offset], data_[location + 3 + (count_ - 1) * offset]);
		}
		
		int GetCount()
		{
			return count_;
		}

	private:
		float* data_;
		ShaderLayout layout_;
		int count_;
	};

}