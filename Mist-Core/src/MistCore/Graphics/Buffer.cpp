#include "glpch.h"

#include "Buffer.h"
#include "RendererAPI.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Mist {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: MCORE_ASSERT(false, "RendererAPI not supported."); return nullptr;
		case RendererAPI::API::Vulkan: MCORE_ASSERT(false, "Vulkan is not supported yet."); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLVertexBuffer(vertices, size);
		}

		MCORE_ASSERT(false, "Cannot bind the Renderer.");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: MCORE_ASSERT(false, "RendererAPI not supported."); return nullptr;
		case RendererAPI::API::Vulkan: MCORE_ASSERT(false, "Vulkan is not supported yet."); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLIndexBuffer(indices, size);
		}

		MCORE_ASSERT(false, "Cannot bind the Renderer.");
		return nullptr;
	}

}