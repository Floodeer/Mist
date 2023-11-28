#pragma once

#include <MistCore.h>
#include <MistCoreUtils.h>
#include "Platform/OpenGL/OpenGLShader.h"
#include "MistCore/Graphics/Texture.h"
#include "MistCore/Graphics/VertexArray.h"
#include "MistCore/Camera/OrthographicCameraController.h"

using namespace Mist;

class AppLayer : public Layer
{
public:
	AppLayer();
	virtual ~AppLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnEvent(Event& event) override;
	virtual void OnUpdate(Timestep ts) override;
	virtual void OnImGuiRender() override;
private:
	OpenGLShader* m_Shader;
	OrthographicCameraController m_CameraController;

	GLuint m_QuadVA, m_QuadVB, m_QuadIB;

	glm::vec4 m_SquareBaseColor = { 0.8f, 0.2f, 0.3f, 1.0f };
	glm::vec4 m_SquareAlternateColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	glm::vec4 m_SquareColor = m_SquareBaseColor;
};