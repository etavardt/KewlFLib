#pragma once

#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		class VertexArray
		{
		private:
			unsigned int m_ID;
		public:
			VertexArray();
			~VertexArray();

			void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
			void Bind() const;
			void Unbind() const;

			inline unsigned int GetID() const {
				return m_ID;
			}
		};
	} // namespace OpenGL
} // namespace Kewl