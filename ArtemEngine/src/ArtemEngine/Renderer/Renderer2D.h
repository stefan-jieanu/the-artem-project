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

		Shared<VertexArray> vertexArray;
		Shared<VertexBuffer> vertexBuffer;
		Shared<IndexBuffer> indexBuffer;

		// The number of indices added 
		uint32_t batchIndicesCount;

		// The number of vertices added
		uint32_t batchVerticesCount;

		// These will be Vertex<> arrays used to store the vertex data 
		void* quadVertexBufferBase = nullptr;
		void* quadVertexBufferPtr = nullptr;

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
			shader->Bind();

			// For now we will assume that all shaders have a u_ProjectionView uniform
			// Might want to change this in the future to bo more dynamic
			shader->SetUniformMat4("u_ProjectionView", sBatchData.camera.GetProjectionViewMatrix());

			sBatchData.vertexArray = VertexArray::Create();

			// Create the vertex buffer to have the size of maximum vertices * the size of a vertex
			sBatchData.vertexBuffer = VertexBuffer::Create(sBatchData.maxVertices * shader->GetLayoutSize());

			sBatchData.vertexBuffer->SetLayout(shader->GetLayout());

			// Set the number of added vertices and indices to 0 (none)
			sBatchData.batchIndicesCount = 0;
			sBatchData.batchVerticesCount = 0;


			VertexData vd = VertexData();

			//sBatchData.quadVertexBufferBase = new Vertex<T>[sBatchData.maxVertices];

			sBatchData.quadVertexBufferPtr = sBatchData.quadVertexBufferBase;
		}

		static void Submit()
		{

		}

		static void EndBatch()
		{

		}

		static void Flush()
		{

		}

		static void FlushAndReset()
		{

		}
	};

}

