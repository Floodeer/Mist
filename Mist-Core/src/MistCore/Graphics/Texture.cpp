#include "Texture.h"

#include "Platform/OpenGL/OpenGLTexture.h"
#include "MistCore/Graphics/Renderer.h"

namespace Mist {

	std::shared_ptr<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: MCORE_ASSERT(false, "RendererAPI not supported."); return nullptr;
		case RendererAPI::API::Vulkan: MCORE_ASSERT(false, "Vulkan is not supported yet."); return nullptr;
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLTexture2D>(path);
		}

		MCORE_ASSERT(false, "Cannot bind the Renderer.");
		return nullptr;
	}
}