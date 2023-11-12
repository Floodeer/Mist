#include "glpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Mist {

	VertexArray* VertexArray::Create()
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: MCORE_ASSERT(false, "RendererAPI not supported."); return nullptr;
		case RendererAPI::API::Vulkan: MCORE_ASSERT(false, "Vulkan is not supported yet."); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}

		MCORE_ASSERT(false, "Cannot bind the Renderer.");
		return nullptr;
	}
}