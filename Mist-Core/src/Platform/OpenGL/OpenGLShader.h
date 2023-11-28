#pragma once

#include "MistCore/Graphics/Shader.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace Mist {

	class OpenGLShader : public Shader
	{

	public:

		OpenGLShader(const std::string& source, const std::string& fragment);

		virtual ~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		void UploadInt(const std::string& name, int value);
		
		void UploadFloat(const std::string& name, float value);
		void UploadFloat2(const std::string& name, const glm::vec2& value);
		void UploadFloat3(const std::string& name, const glm::vec3& value);
		void UploadFloat4(const std::string& name, const glm::vec4& value);

		void UploadMat3(const std::string& name, const glm::mat3& matrix);
		void UploadMat4(const std::string& name, const glm::mat4& matrix);

		GLuint GetRendererID() { return m_RenderID; }

		static OpenGLShader* FromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

	private:
		OpenGLShader() = default;

		void LoadFromGLSLTextFiles(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
		
		GLuint CompileShader(GLenum type, const std::string& source);

	private:
		GLuint m_RenderID;
	};
}