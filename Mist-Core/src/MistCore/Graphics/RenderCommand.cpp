#include "glpch.h"

#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRenderer.h"

namespace Mist {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}