#pragma once
#include <stdio.h>

// For use in the Artem application
#include "ArtemEngine/Application.h"
#include "ArtemEngine/Layer.h"
#include "ArtemEngine/Log.h"

#include "ArtemEngine/Input.h"
#include "ArtemEngine/KeyCode.h"

// ----------- Renderer -------------
#include "ArtemEngine/Renderer/Renderer.h"
#include "ArtemEngine/Renderer/RenderCommand.h"

#include "ArtemEngine/Renderer/Buffers.h"
#include "ArtemEngine/Renderer/Shader.h"
#include "ArtemEngine/Renderer/VertexArray.h"
// ----------------------------------

#include "ArtemEngine/Renderer/OrthographicCamera.h"

// ---------- Entry Point -----------
#include "ArtemEngine/EntryPoint.h"
// ----------------------------------

// Undefine logger macros specific to the engine
#undef LOG_CORE_TRACE
#undef LOG_CORE_DEBUG
#undef LOG_CORE_INFO
#undef LOG_CORE_WARN
#undef LOG_CORE_ERROR