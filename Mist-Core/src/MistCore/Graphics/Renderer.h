#pragma once

#include "glpch.h"
#include "Shader.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "MistCore/Camera/OrthographicCamera.h"

#include <glm/glm.hpp>

namespace Mist {

	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(OrthographicCamera& camera);
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