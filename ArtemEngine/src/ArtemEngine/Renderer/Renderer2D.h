#pragma once

#include "OrthographicCamera.h"
#include "Color.h"
#include "Texture.h"
#include "Vertex.h"
#include "Shader.h"
#include "RenderCommand.h"
#include "VertexArray.h"

namespace ArtemEngine {

	struct BatchData
	{
		// The maximum number of vertices that can be drawn in one batch
		static const uint32_t maxVertices = 10000;

		// The maximum number of indices that can be drawn in one batch
		static const uint32_t maxIndices = 12000;

		// The array holding the indices before they are passed to the Index Buffer
		uint32_t* indices = new uint32_t[maxIndices];

		Shared<VertexArray> vertexArray;
		Shared<VertexBuffer> vertexBuffer;
		Shared<IndexBuffer> indexBuffer;
		Shared<Shader> shader;

		// The number of indices added 
		uint32_t batchIndicesCount;

		// The number of vertices added
		uint32_t batchVerticesCount;

		// The VertexData object usedd to store the vertex data 
		Shared<VertexData> vertexData;

		// The VertexData float* that hold the data itself 
		void* vertexBufferBase = nullptr;
		void* vertexBufferPtr = nullptr;

		// The camera that will be used for drawing 
		OrthographicCamera camera;
	};

	static BatchData sBatchData;

	class Renderer2D
	{
	private:

	public:

		static void Init()
		{

		}

		static void Terminate()
		{

		}

		static void SetCamera(const OrthographicCamera& camera)
		{
			sBatchData.camera = camera;
		}

		static void BeginBatch(Shared<Shader> shader)
		{
			sBatchData.shader = shader;

			shader->Bind();

			// shader->PrintShaderUniforms();

			// For now we will assume that all shaders have a u_ProjectionView uniform
			// Might want to change this in the future to bo more dynamic
			shader->SetUniformMat4("u_ProjectionView", sBatchData.camera.GetProjectionViewMatrix());

			sBatchData.vertexArray = VertexArray::Create();

			// Create the vertex buffer to have the size of maximum vertices * the size of a vertex
			sBatchData.vertexBuffer = VertexBuffer::Create(sBatchData.maxVertices * shader->GetLayoutSize());

			sBatchData.vertexBuffer->SetLayout(shader->GetLayout());


			sBatchData.vertexArray->AddVertexBuffer(sBatchData.vertexBuffer);

			// Set the number of added vertices and indices to 0 (none)
			sBatchData.batchIndicesCount = 0;
			sBatchData.batchVerticesCount = 0;

			// Test 
			/*Shared<VertexData> vd = MakeShared<VertexData>(shader->GetLayout(), 4);
			vd->SetData("_position", { 10.5f, -10.5f, 1.0f }, 0);
			vd->SetData("_position", { -10.5f, -10.5f, 1.0f }, 1);
			vd->SetData("_position", { -10.5f, 10.5f, 1.0f }, 2);
			vd->SetData("_position", { 10.5f, 10.5f, 1.0f }, 3);

			vd->SetData("_color", Color::Red, 0);
			vd->SetData("_color", Color::White, 1);
			vd->SetData("_color", Color::Blue, 2);
			vd->SetData("_color", Color::Green, 3);

			LOG_CORE_DEBUG(vd->GetData<Math::Vector3>("_position", 0));
			LOG_CORE_DEBUG(vd->GetData<Math::Vector4>("_color", 0));

			LOG_CORE_DEBUG(vd->GetData<Math::Vector3>("_position", 1));
			LOG_CORE_DEBUG(vd->GetData<Math::Vector4>("_color", 1));

			LOG_CORE_DEBUG(vd->GetData<Math::Vector3>("_position", 2));
			LOG_CORE_DEBUG(vd->GetData<Math::Vector4>("_color", 3));

			LOG_CORE_DEBUG(vd->GetData<Math::Vector3>("_position", 3));
			LOG_CORE_DEBUG(vd->GetData<Math::Vector4>("_color", 3));*/

			sBatchData.vertexData = MakeShared<VertexData>(shader->GetLayout(), sBatchData.maxVertices);
		}

		static void Draw(Shared<VertexData>& vd, uint32_t* indices, int indicesCount)
		{
			// Setting the vertex data which will later be used in the vertex buffer
			for (int i = 0; i < vd->GetCount(); i++)
			{
				//sBatchData.vertexData->GetData()[i + sBatchData.batchVerticesCount] = vd->GetData()[i];

				sBatchData.vertexData->SetData("_position", vd->GetData<Math::Vector3>("_position", i), i + sBatchData.batchVerticesCount);
				//LOG_CORE_DEBUG(sBatchData.vertexData->GetData<Math::Vector3>("_position", i));
			}

			// Increasing the vertices count of the batch data
			sBatchData.batchVerticesCount += vd->GetCount();

			// Setting the indices which will be used by the index buffer
			for (int i = 0; i < indicesCount; i++)
			{
				indices[i + sBatchData.batchIndicesCount] = indices[i];
			}

			// Increasing the index count of the batch data
			sBatchData.batchIndicesCount += indicesCount;
		}

		static void EndBatch()
		{
			// Size of the data sent to the VBO
			uint32_t dataSize = sBatchData.shader->GetLayoutSize() * sBatchData.batchVerticesCount;
			
			// Buffer the existing vertex data to the VBO
			sBatchData.vertexBuffer->SetData(sBatchData.vertexData->GetData(), dataSize);

			// Generate the index buffer 
			sBatchData.indexBuffer = IndexBuffer::Create(sBatchData.indices, sBatchData.batchIndicesCount);

			// Set the index buffer to the VAO
			sBatchData.vertexArray->SetIndexBuffer(sBatchData.indexBuffer);

			sBatchData.indexBuffer->Bind();

			Flush();
		}

		static void Flush() 
		{
			RenderCommand::DrawIndexed(sBatchData.vertexArray, sBatchData.indexBuffer->GetCount());

			LOG_CORE_DEBUG(sBatchData.vertexData->GetData<Math::Vector3>("_position", 0));
			LOG_CORE_DEBUG(sBatchData.vertexData->GetData<Math::Vector3>("_position", 1));
			LOG_CORE_DEBUG(sBatchData.vertexData->GetData<Math::Vector3>("_position", 2));
			LOG_CORE_DEBUG(sBatchData.vertexData->GetData<Math::Vector3>("_position", 3));
		}

		static void FlushAndReset()
		{
		}
	};

}

