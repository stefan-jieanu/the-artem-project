#include "aepch.h"
#include "Renderer2D.h"

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

	void Renderer2D::Init()
	{
		Vertex<float, char, int> v1;
	}

	void Renderer2D::Terminate()
	{
	}

	void Renderer2D::SetCamera(const OrthographicCamera& camera)
	{
		sBatchData.camera = camera;
	}

	

	template<typename T>
	void Renderer2D::BeginBatch(T vertexType, Shared<Shader> shader)
	{
		shader->Bind();

		// For now we will assume that all shaders have a u_ProjectionView uniform
		// Might want to change this in the future to bo more dynamic
		shader->SetUniformMat4("u_ProjectionView", camera.GetProjectionViewMatrix());

		sBatchData.vertexArray = VertexArray::Create();

		// Create the vertex buffer to have the size of maximum vertices * the size of a vertex
		sBatchData.vertexBuffer = VertexBuffer::Create(sBatchData.maxVertices * sizeof(T));

		// TODO: Overload SetLayout() to generate a layout from a VertexType
		sBatchData.vertexBuffer->SetLayout({
				
			});


		// Set the number of added vertices and indices to 0 (none)
		sBatchData.batchIndicesCount = 0;
		sBatchData.batchVerticesCount = 0;

		sBatchData.quadVertexBufferBase = (Vertex<int, int>) new Vertex<int, int>[sBatchData.maxVertices];

		sRendererData.quadVertexBufferPtr = sRendererData.quadVertexBufferBase;

		sRendererData.textureSlotIndex = 1;
	}

	void Renderer2D::Flush()
	{

	}

	void Renderer2D::FlushAndReset()
	{

	}

	void Renderer2D::EndBatch()
	{

	}

}