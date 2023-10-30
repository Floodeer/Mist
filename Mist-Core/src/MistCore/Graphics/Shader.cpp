#include "glpch.h"
#include "Shader.h"

#include <Platform/OpenGL/OpenGLShader.h>
#include <MistCore/Graphics/Renderer.h>

namespace MistCore {


	Shader* Shader::CreateShader(const std::string& source, const std::string& fragment)
	{
		switch (RendererAPI::GetAPI())
		{
		        case RendererAPI::API::None: MCORE_ASSERT(false, "RendererAPI not supported."); return nullptr;
				case RendererAPI::API::Vulkan: MCORE_ASSERT(false, "Vulkan is not supported yet."); return nullptr;
				case RendererAPI::API::OpenGL: return new OpenGLShader(source, fragment);
		}

		MCORE_ASSERT(false, "Cannot bind the Renderer.");
		return nullptr;
	}
}