#include "VertexArray.hpp"

#include "OpenGLDebug.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		VertexArray::VertexArray() {
			//	GLCall(glGenVertexArrays(1, &m_ID));
			GLCall(glCreateVertexArrays(1, &m_ID));
		}

		VertexArray::~VertexArray() {
			GLCall(glDeleteVertexArrays(1, &m_ID))
		}

		void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
			Bind();
			vb.Bind();
			const auto& elements = layout.GetElements();
			unsigned char* offset = 0;
			//for (const auto& element : elements) {
			for (unsigned int i = 0; i < elements.size(); i++)
			{
				const auto& element = elements[i];
				GLCall(glEnableVertexAttribArray(i));
				//GLCall(glEnableVertexArrayAttrib(vb.GetID(), i));
				GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
				offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
			}
		}

		void VertexArray::Bind() const {
			GLCall(glBindVertexArray(m_ID));
		}

		void VertexArray::Unbind() const {
			GLCall(glBindVertexArray(0));
		}
	} // namespace OpenGL
} // namespace Kewl