#include "glpch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace MistCore {

	static GLenum ShaderDataTypeTransform(ShaderDataType type)
	{
		switch (type)
		{
		    case MistCore::ShaderDataType::Float: return GL_FLOAT;
			case MistCore::ShaderDataType::Float2: return GL_FLOAT;
			case MistCore::ShaderDataType::Float3: return GL_FLOAT;
			case MistCore::ShaderDataType::Float4: return GL_FLOAT;

			case MistCore::ShaderDataType::Mat3: return GL_FLOAT;
			case MistCore::ShaderDataType::Mat4: return GL_FLOAT;

			case MistCore::ShaderDataType::Int: return GL_INT;
			case MistCore::ShaderDataType::Int2: return GL_INT;
			case MistCore::ShaderDataType::Int3: return GL_INT;
			case MistCore::ShaderDataType::Int4: return GL_INT;

			case MistCore::ShaderDataType::Bool: return GL_BOOL;
		}

		MCORE_ASSERT(false, "Invalid ShaderDataType");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RenderID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RenderID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		MCORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer empty layout");

		glBindVertexArray(m_RenderID);
		vertexBuffer->Bind();

		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(),
				ShaderDataTypeTransform(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)(intptr_t)element.Offset);

			m_VertexBufferIndex++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RenderID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}

}