#include "aepch.h"
#include "Renderer2D.h"

#include "RenderCommand.h"
#include "VertexArray.h"
#include "Shader.h"

namespace ArtemEngine {

	struct QuadVertex
	{
		Math::Vector3 position;
		Color color;
		Math::Vector2 texCoord;
		float texIndex;
	};

	struct RendererData
	{
		static const uint32_t maxQuads = 10000;
		static const uint32_t maxVertices = maxQuads * 4;
		static const uint32_t maxIndices = maxQuads * 6;
		static const uint32_t maxTextureSlots = 32; 

		Shared<VertexArray> vertexArray;
		Shared<VertexBuffer> vertexBuffer;
		Shared<Shader> shader;
		Shared<Texture> whiteTexture;

		uint32_t quadIndexCount = 0;
		QuadVertex* quadVertexBufferBase = nullptr;
		QuadVertex* quadVertexBufferPtr = nullptr;

		// Starts at 1 because 0 is used for the white texture
		uint32_t textureSlotIndex = 1; 
		std::array<Shared<Texture>, maxTextureSlots> textureSlots;

		Math::Vector4 quadVertexPositions[4];
	};

	static RendererData sRendererData;

	void Renderer2D::Init()
	{
		sRendererData.vertexArray = VertexArray::Create();

		sRendererData.vertexBuffer = VertexBuffer::Create(sRendererData.maxVertices * sizeof(QuadVertex));
		sRendererData.vertexBuffer->SetLayout({
				{ ShaderDataType::Float3, "_position" },
				{ ShaderDataType::Float4, "_color" },
				{ ShaderDataType::Float2, "_texCoord" },
				{ ShaderDataType::Float, "_texIndex" }
			});
		sRendererData.vertexArray->AddVertexBuffer(sRendererData.vertexBuffer);

		sRendererData.quadVertexBufferBase = new QuadVertex[sRendererData.maxVertices];

		uint32_t* quadIndices = new uint32_t[sRendererData.maxIndices];

		uint32_t offset = 0;
		for (uint32_t i = 0; i < sRendererData.maxIndices; i += 6)
		{
			quadIndices[i + 0] = offset + 0;
			quadIndices[i + 1] = offset + 1;
			quadIndices[i + 2] = offset + 2;

			quadIndices[i + 3] = offset + 2;
			quadIndices[i + 4] = offset + 3;
			quadIndices[i + 5] = offset + 0;

			offset += 4;
		}

		Shared<IndexBuffer> indexBuffer = IndexBuffer::Create(quadIndices, sRendererData.maxIndices);
		sRendererData.vertexArray->SetIndexBuffer(indexBuffer);
		// TODO: This might cause an error if the data is not fully uploaded to the GPU by the time we delete it (in the future)
		// so FIX IT!
		delete[] quadIndices;

		sRendererData.whiteTexture = Texture::Create(1, 1);
		uint32_t whiteTextureData = 0xffffffff;
		sRendererData.whiteTexture->SetData(&whiteTextureData, sizeof(uint32_t));

		int32_t samplers[sRendererData.maxTextureSlots];
		for (uint32_t i = 0; i < sRendererData.maxTextureSlots; i++)
			samplers[i] = i;

		sRendererData.shader = Shader::Create("E:/Work/Artem/ArtemEngine/res/Shaders/texture.glsl");
		sRendererData.shader->Bind();

		sRendererData.shader->SetUniformIntArray("u_textures", samplers, sRendererData.maxTextureSlots);

		sRendererData.textureSlots[0] = sRendererData.whiteTexture;

		sRendererData.quadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
		sRendererData.quadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
		sRendererData.quadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
		sRendererData.quadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };
	}

	void Renderer2D::Terminate()
	{
	}

	void Renderer2D::BeginScene(const OrthographicCamera& camera)
	{
		sRendererData.shader->Bind();
		sRendererData.shader->SetUniformMat4("u_ProjectionView", camera.GetProjectionViewMatrix());

		sRendererData.quadIndexCount = 0;
		sRendererData.quadVertexBufferPtr = sRendererData.quadVertexBufferBase;

		sRendererData.textureSlotIndex = 1;
	}

	void Renderer2D::Flush()
	{
		// Bind textures
		for (uint32_t i = 0; i < sRendererData.textureSlotIndex; i++)
		{
			sRendererData.textureSlots[i]->Bind(i);
		}

		RenderCommand::DrawIndexed(sRendererData.vertexArray,  sRendererData.quadIndexCount);
	}

	void Renderer2D::FlushAndReset()
	{
		EndScene();

		sRendererData.quadIndexCount = 0;
		sRendererData.quadVertexBufferPtr = sRendererData.quadVertexBufferBase;

		sRendererData.textureSlotIndex = 1;
	}

	void Renderer2D::EndScene()
	{
		uint32_t dataSize = (uint8_t*)sRendererData.quadVertexBufferPtr - (uint8_t*)sRendererData.quadVertexBufferBase;
		sRendererData.vertexBuffer->SetData(sRendererData.quadVertexBufferBase, dataSize);

		Flush();
	}

	void Renderer2D::DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Color& color, float rotation)
	{
		DrawQuad({ position.x, position.y, 0 }, size, color, rotation);
	}

	void Renderer2D::DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Color& color, float rotation)
	{
		if (sRendererData.quadIndexCount >= RendererData::maxIndices)
			FlushAndReset();

		// White texture index
		const float texIndex = 0.0f;

		Math::Matrix4 transform = Math::Translate(position)
			* Math::Rotate(Math::Radians(rotation), Math::Vector3(0, 0, 1))
			* Math::Scale(Math::Vector3(size.x, size.y, 1.0f));

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[0];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = texIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[1];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = texIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[2];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = texIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[3];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = texIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadIndexCount += 6;
	}

	void Renderer2D::DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Shared<Texture>& texture, float rotation)
	{
		DrawQuad({ position.x, position.y, 0 }, size, texture, rotation);
	}

	void Renderer2D::DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Shared<Texture>& texture, float rotation)
	{
		const Color color = Color::White;

		if (sRendererData.quadIndexCount >= RendererData::maxIndices)
			FlushAndReset();

		float textureIndex = 0.0f;

		for (uint32_t i = 1; i < sRendererData.textureSlotIndex; i++)
		{
			if (*sRendererData.textureSlots[i].get() == *texture.get())
			{
				textureIndex = (float)i;
				break;
			}
		}

		if (textureIndex == 0.0f)
		{
			textureIndex = (float)sRendererData.textureSlotIndex;
			sRendererData.textureSlots[sRendererData.textureSlotIndex] = texture;
			sRendererData.textureSlotIndex++;
		}

		// White texture index
		const float texIndex = 0.0f; 

		Math::Matrix4 transform = Math::Translate(position)
			* Math::Rotate(Math::Radians(rotation), Math::Vector3(0, 0, 1)) 
			* Math::Scale(Math::Vector3(size.x, size.y, 1.0f));

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[0];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[1];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[2];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[3];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadIndexCount += 6;


#if 0
		sRendererProps.shader->SetUniformFloat4("u_Color", { 1.0f, 1.0f, 1.0f, 1.0f });
		texture->Bind();

		Math::Matrix4 transform = Math::Translate(position) * Math::Rotate(Math::Radians(rotation), Math::Vector3(0, 0, 1)) * Math::Scale(size);
		sRendererProps.shader->SetUniformMat4("u_Transform", transform);

		sRendererProps.vertexArray->Bind();
		RenderCommand::DrawIndexed(sRendererProps.vertexArray);
#endif
	}

	/*void Renderer2D::DrawQuad(const Math::Vector3& position, const Math::Vector2& size, uint32_t texID, float rotation = 0.0f)
	{
		const Color color = Color::White;

		if (sRendererData.quadIndexCount >= RendererData::maxIndices)
			FlushAndReset();

		float textureIndex = 0.0f;

		for (uint32_t i = 1; i < sRendererData.textureSlotIndex; i++)
		{
			if (*sRendererData.textureSlots[i].get() == *texture.get())
			{
				textureIndex = (float)i;
				break;
			}
		}

		if (textureIndex == 0.0f)
		{
			textureIndex = (float)sRendererData.textureSlotIndex;
			sRendererData.textureSlots[sRendererData.textureSlotIndex] = texture;
			sRendererData.textureSlotIndex++;
		}



		// White texture index
		const float texIndex = 0.0f;

		Math::Matrix4 transform = Math::Translate(position)
			* Math::Rotate(Math::Radians(rotation), Math::Vector3(0, 0, 1))
			* Math::Scale(Math::Vector3(size.x, size.y, 1.0f));

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[0];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[1];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 0.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[2];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 1.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadVertexBufferPtr->position = transform * sRendererData.quadVertexPositions[3];
		sRendererData.quadVertexBufferPtr->color = color;
		sRendererData.quadVertexBufferPtr->texCoord = { 0.0f, 1.0f };
		sRendererData.quadVertexBufferPtr->texIndex = textureIndex;
		sRendererData.quadVertexBufferPtr++;

		sRendererData.quadIndexCount += 6;
	}*/

	/*void Renderer2D::DrawQuad(const Math::Vector2& position, const Math::Vector2& size, const Shared<Texture>& texture, const Color& color, float rotation)
	{
		DrawQuad({ position.x, position.y, 0.0f }, size, texture, color, rotation);
	}

	void Renderer2D::DrawQuad(const Math::Vector3& position, const Math::Vector2& size, const Shared<Texture>& texture, const Color& color, float rotation)
	{
		sRendererProps.shader->SetUniformFloat4("u_Color", color);
		texture->Bind();

		Math::Matrix4 transform = Math::Translate(position) * Math::Rotate(Math::Radians(rotation), Math::Vector3(0, 0, 1)) * Math::Scale(size);
		sRendererProps.shader->SetUniformMat4("u_Transform", transform);

		sRendererProps.vertexArray->Bind();
		RenderCommand::DrawIndexed(sRendererProps.vertexArray);
	}*/

}