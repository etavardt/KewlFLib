#pragma once

#include <Kewl/String.hpp>

#include "Kewl/Util/Image.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		class Texture
		{
		private:
			unsigned int m_ID = 0;

			Kewl::Image m_Image;

			void PrepGLTex();
			Texture() = delete;
		public:
			Texture(int width, int height);
			Texture(const std::string& path);
			~Texture();

			inline unsigned int GetID() const { return m_ID; }
			inline Kewl::Image& GetImage() { return m_Image; }
			void ResendTex();

			void Bind(unsigned int slot = 0) const;
			void Unbind() const;

			void NewBlankTexture(int width, int height);
			void Load(const std::string& filename);
			//void save(const std::string& filename);
		};
	} // namespace OpenGL
} // namespace Kewl