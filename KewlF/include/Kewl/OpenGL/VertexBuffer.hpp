#pragma once

#include <vector>

namespace Kewl
{
	namespace OpenGL
	{
		class VertexBuffer
		{
		private:
			unsigned int m_ID;
		public:
			VertexBuffer(const void* data, size_t size);
			VertexBuffer(const std::vector<float> vec);
			~VertexBuffer();

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetID() const {
				return m_ID;
			}
		};
	} // namespace OpenGL
} // namespace Kewl