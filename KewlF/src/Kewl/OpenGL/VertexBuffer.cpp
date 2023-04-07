#include "VertexBuffer.hpp"

#include <glad/glad.h>
#include "OpenGLDebug.hpp"
#include "Renderer.hpp"

namespace Kewl
{
    namespace OpenGL
    {
        VertexBuffer::VertexBuffer(const void* data, size_t size) {
            //    GLCall(glGenBuffers(1, &m_ID));
            GLCall(glCreateBuffers(1, &m_ID));
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
            GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));
        }

        VertexBuffer::VertexBuffer(const std::vector<float> vec) {
            //    GLCall(glGenBuffers(1, &m_ID));
            GLCall(glCreateBuffers(1, &m_ID));
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
            GLCall(glBufferData(GL_ARRAY_BUFFER, vec.size() * sizeof(vec[0]), vec.data(), GL_DYNAMIC_DRAW));
        }

        VertexBuffer::~VertexBuffer() {
            GLCall(glDeleteBuffers(1, &m_ID));
        }

        void VertexBuffer::Bind() const {
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_ID));
        }

        void VertexBuffer::Unbind() const {
            GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        }
    } // namespace OpenGL
} // namespace Kewl