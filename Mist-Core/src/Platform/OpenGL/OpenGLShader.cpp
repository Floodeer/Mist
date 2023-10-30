#include "glpch.h"
#include "OpenGLShader.h"

#include "glad/glad.h"
#include <glm/gtc/type_ptr.hpp>

namespace MistCore {

	OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
	{

		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const GLchar* source = vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		glCompileShader(vertexShader);

		GLint id = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &id);
		if (id == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);

			MCORE_ASSERT(infoLog.data());
			MCORE_ASSERT("Vertex shader compilation failed!");
			return;
		}

		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &id);

		if (id == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);

			MCORE_ASSERT(infoLog.data());
			MCORE_ASSERT("Fragment shader compilation failed!");
			return;
		}

		m_RenderID = glCreateProgram();
		GLuint program = m_RenderID;

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(program);


			glDeleteShader(fragmentShader);
			glDeleteShader(vertexShader);

			MCORE_ASSERT(infoLog.data());
			MCORE_ASSERT("Program link failed!");
			return;
		}

		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_RenderID);
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(m_RenderID);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::UploadInt(const std::string& name, int value)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniform1i(location, value);
	}

	void OpenGLShader::UploadFloat(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniform1f(location, value);
	}


	void OpenGLShader::UploadFloat2(const std::string& name, const glm::vec2& value)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniform2f(location, value.x, value.y);
	}

	void OpenGLShader::UploadFloat3(const std::string& name, const glm::vec3& value)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniform3f(location, value.x, value.y, value.z);
	}


	void OpenGLShader::UploadFloat4(const std::string& name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::UploadMat3(const std::string& name, const glm::mat3& matrix)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));

	}

	void OpenGLShader::UploadMat4(const std::string& name, const glm::mat4& matrix)
	{
		GLint location = glGetUniformLocation(m_RenderID, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));

	}
}