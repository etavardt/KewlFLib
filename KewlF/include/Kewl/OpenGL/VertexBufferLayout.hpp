#pragma once

#include <vector>
#include <glad/glad.h>
#include "Kewl/OpenGL/OpenGLDebug.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		struct VertexBufferElement
		{
			unsigned int type;
			unsigned int count;
			unsigned char normalized;

			static unsigned int GetSizeOfType(unsigned int type) {
				switch (type)
				{
					case GL_FLOAT: return 4;
					case GL_UNSIGNED_INT: return 4;
					case GL_UNSIGNED_BYTE: return 1;
				}
				ASSERT(false);
				return 0;
			}
		};

		class VertexBufferLayout
		{
		private:
			std::vector<VertexBufferElement> m_Elements;
			unsigned int m_Stride;
		public:
			VertexBufferLayout() : m_Stride(0) {}
			~VertexBufferLayout() {};

			template<typename T>
			void Push(unsigned int count) {
				assert(false);
			}

			template<>
			void Push<float>(unsigned int count) {
				m_Elements.push_back(VertexBufferElement(GL_FLOAT, count, GL_FALSE));
				//m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
				m_Stride += count * sizeof(GLfloat);
			}
			template<>
			void Push<unsigned int>(unsigned int count) {
				//m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
				m_Elements.push_back(VertexBufferElement(GL_UNSIGNED_INT, count, GL_FALSE));
				m_Stride += count * sizeof(GLuint);
			}
			template<>
			void Push<unsigned char>(unsigned int count) {
				m_Elements.push_back(VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_TRUE));
				//m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
				m_Stride += count * sizeof(GLbyte);
			}

			inline const std::vector<VertexBufferElement>& GetElements() const {
				return m_Elements;
			}
			inline const unsigned int GetStride() const {
				return m_Stride;
			}
		};
	} // namespace OpenGL
} // namespace Kewl