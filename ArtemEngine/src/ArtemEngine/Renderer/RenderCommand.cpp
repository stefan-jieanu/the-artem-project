#pragma once

#include "aepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace ArtemEngine {

	RendererAPI* RenderCommand::sRendererAPI_ = new OpenGLRendererAPI;

}