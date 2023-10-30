#pragma once

#include "glpch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

#include <glm/glm.hpp>

namespace MistCore {

	class RendererAPI
	{
	public:
	
		enum class API
		{
			None = 0, OpenGL = 1, Vulkan = 2
		};
		
	public:
		virtual void Init();
		virtual void Clear() = 0;

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static API GetAPI()
		{
			return g_API;
		}
		
	private:
		static API g_API;
	};

	class Renderer
	{
	public:
		static void Init();

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

	private:
		struct Scene
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scene* g_Scene;
	};
}