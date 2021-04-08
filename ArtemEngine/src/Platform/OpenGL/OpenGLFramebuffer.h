#pragma once

#include "ArtemEngine/Renderer/Framebuffer.h"
#include "OpenGLTexture.h"

namespace ArtemEngine {

	class OpenGLFramebuffer : public Framebuffer
	{
	public:
		OpenGLFramebuffer(const FramebufferProperties& props);
		~OpenGLFramebuffer();

		void Invalidate();

		const FramebufferProperties& GetProperties() const override { return properties_; }

		void Bind() const override;
		void Unbind() const override;

		uint32_t GetColorAttachmentID() const override { return colorAttachment_; }
		const Shared<Texture> GetColorTexture() const override { return colorTexture_; }
	private:
		uint32_t framebufferID_;
		uint32_t colorAttachment_, depthAttachment_;

		FramebufferProperties properties_;
	};

}