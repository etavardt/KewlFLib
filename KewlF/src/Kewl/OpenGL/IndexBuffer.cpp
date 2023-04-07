#include "IndexBuffer.hpp"

#include <glad/glad.h>
#include "OpenGLDebug.hpp"
#include "Renderer.hpp"

namespace Kewl
{
    namespace OpenGL
    {

        IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : m_Count(count) {
            ASSERT(sizeof(unsigned int) == sizeof(GLuint));

            GLCall(glGenBuffers(1, &m_ID));
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(unsigned int), data, GL_STATIC_DRAW));
        }

        IndexBuffer::IndexBuffer(const std::vector<unsigned int>& vec) : m_Count(static_cast<unsigned int>(vec.size())) {
            ASSERT(sizeof(unsigned int) == sizeof(GLuint));

            GLCall(glGenBuffers(1, &m_ID));
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
            GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(vec[0]), vec.data(), GL_DYNAMIC_DRAW));
        }


        IndexBuffer::~IndexBuffer() {
            GLCall(glDeleteBuffers(1, &m_ID));
        }

        void IndexBuffer::Bind() const {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
        }

        void IndexBuffer::Unbind() const {
            GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
        }
    } // namespace OpenGL
} // namespace Kewl