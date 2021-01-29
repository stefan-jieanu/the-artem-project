#pragma once
#include <stdio.h>

// For use in the Artem application
#include "ArtemEngine/Core/Application.h"
#include "ArtemEngine/Core/Layer.h"
#include "ArtemEngine/Core/Log.h"

#include "ArtemEngine/Core/DeltaTime.h"

#include "ArtemEngine/Core/Input.h"
#include "ArtemEngine/Core/KeyCode.h"

// ----------- Renderer -------------
#include "ArtemEngine/Renderer/Renderer.h"
#include "ArtemEngine/Renderer/RenderCommand.h"

#include "ArtemEngine/Renderer/Buffers.h"
#include "ArtemEngine/Renderer/Shader.h"
#include "ArtemEngine/Renderer/VertexArray.h"
// ----------------------------------

#include "ArtemEngine/OrthographicCameraController.h"

// Undefine logger macros specific to the engine
#undef LOG_CORE_TRACE
#undef LOG_CORE_DEBUG
#undef LOG_CORE_INFO
#undef LOG_CORE_WARN
#undef LOG_CORE_ERROR