#include "Kewl/OpenGL/Renderer.hpp"

#include "Kewl/OpenGL/OpenGLDebug.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
			shader.Bind();
			va.Bind();
			ib.Bind();
			GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
			//GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_INT, nullptr)); // Test for Error
		}

		/*
		void Renderer::clear() const {
			GLCall(glClear(GL_COLOR_BUFFER_BIT));
		}
		*/
	} // namespace OpenGL
} // namespace Kewl