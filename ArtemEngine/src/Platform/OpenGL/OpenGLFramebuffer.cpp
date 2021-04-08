#include "aepch.h"
#include "OpenGLFramebuffer.h"

#include <glad/glad.h>

namespace ArtemEngine {

	OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferProperties& props)
		: properties_(props)
	{
		Invalidate();
	}

	OpenGLFramebuffer::~OpenGLFramebuffer()
	{
		glDeleteFramebuffers(1, &framebufferID_);
	}

	void OpenGLFramebuffer::Invalidate()
	{
		// Creating the framebuffer
		glCreateFramebuffers(1, &framebufferID_);
		glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_);

		/* Creating the texture id to use with the framebuffer
		glCreateTextures(GL_TEXTURE_2D, 1, &colorAttachment_);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, properties_.width, properties_.height, 0, GL_RGBA,  GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorAttachment_, 0);
		*/

		colorTexture_ = MakeShared<OpenGLTexture>(properties_.width, properties_.height);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture_->GetTextureID(), 0);
		//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, colorTexture_->get)
		
		//glCreateTextures(GL_TEXTURE_2D, 1, &depthAttachment_);
		//glBindTexture(GL_TEXTURE_2D, depthAttachment_);
		//glTexStorage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, properties_.width, properties_.height);
		//glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, properties_.width, properties_.height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);
		//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, depthAttachment_, 0);

		LOG_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void OpenGLFramebuffer::Bind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, framebufferID_); 
	}

	void OpenGLFramebuffer::Unbind() const
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

}