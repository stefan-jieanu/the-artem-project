#pragma once

#include "ArtemEngine/Renderer/Texture.h"

namespace ArtemEngine {

	struct FramebufferProperties
	{
		uint32_t width, height;
		uint32_t samples = 1;

		bool swapChainTarget = false;
	};

	class Framebuffer
	{
	public:
		virtual ~Framebuffer() {}
		virtual const FramebufferProperties& GetProperties() const = 0;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetColorAttachmentID() const = 0;
		virtual const Shared<Texture> GetColorTexture() const = 0;

		static Shared<Framebuffer> Create(const FramebufferProperties& props);
	protected:
		Shared<Texture> colorTexture_;
		Shared<Texture> depthTexture_;
	};

}