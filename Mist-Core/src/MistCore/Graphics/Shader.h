#pragma once

#include <string>

namespace MistCore {

	class Shader
	{
	public:

		virtual ~Shader() = default;

		virtual void Bind() const = 0;

		virtual void Unbind() const = 0;

		static Shader* CreateShader(const std::string& source, const std::string& fragment);

	};
}