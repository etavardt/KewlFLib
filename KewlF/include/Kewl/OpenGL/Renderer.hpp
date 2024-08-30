#pragma once

#include "Kewl/OpenGL/VertexArray.hpp"
#include "Kewl/OpenGL/IndexBuffer.hpp"
#include "Kewl/OpenGL/Shader.hpp"

namespace Kewl
{
	namespace OpenGL
	{

		class Renderer
		{
		private:
		public:
			inline void clear() const {
				GLCall(glClear(GL_COLOR_BUFFER_BIT));
			}
			void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
		};
	} // namespace OpenGL
} // namespace Kewl