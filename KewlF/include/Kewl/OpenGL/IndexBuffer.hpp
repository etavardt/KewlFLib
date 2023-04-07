#pragma once

#include <vector>

namespace Kewl
{
	namespace OpenGL
	{
		class IndexBuffer
		{
		private:
			unsigned int m_ID;
			unsigned int m_Count;
		public:
			IndexBuffer(const unsigned int* data, unsigned int count);
			IndexBuffer(const std::vector<unsigned int>& vec);
			~IndexBuffer();

			void Bind() const;
			void Unbind() const;

			inline unsigned int GetCount() const {
				return m_Count;
			}
		};
	} // namespace OpenGL
} // namespace Kewl