#include "glpch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace Mist {

	Renderer::Scene* Renderer::g_Scene = new Renderer::Scene;

	void Renderer::Init()
	{

	}

	void Renderer::BeginScene()
	{

	}

	void Renderer::EndScene()
	{

	}

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadMat4("u_ViewProjection", g_Scene->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadMat4("u_Transform", transform);

		vertexArray->Bind();
		//Draw
	}

}