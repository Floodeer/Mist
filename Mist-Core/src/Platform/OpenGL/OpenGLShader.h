#pragma once

#include "MistCore/Graphics/Shader.h"
#include <glm/glm.hpp>

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

	private:
		uint32_t m_RenderID;
	};
}