#include "Texture.hpp"
#include <glad/glad.h>
#include <Kewl/Logger.hpp>

#include "OpenGLDebug.hpp"

namespace Kewl
{
	namespace OpenGL
	{
		Texture::Texture(int width, int height)
		{
			if (m_Image.CreateImage(width, height))
			{
				PrepGLTex();
			}
		}

		Texture::Texture(const std::string& filename)
		{
			if (m_Image.Load(filename))
			{
				PrepGLTex();
			}
		}

		Texture::~Texture()
		{
			GLCall(glDeleteTextures(1, &m_ID));
			//if (m_ImageBuffer != nullptr) delete[] m_ImageBuffer;
			LOG(INFO) << "Destruct Texture" << std::endl;
		}

		void Texture::Bind(unsigned int slot /*= 0*/) const
		{
			GLCall(glActiveTexture(GL_TEXTURE0 + slot));
			GLCall(glBindTexture(GL_TEXTURE_2D, m_ID));
		}

		void Texture::Unbind() const
		{
			GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		}

		void Texture::PrepGLTex()
		{
			GLCall(glGenTextures(1, &m_ID));
			GLCall(glBindTexture(GL_TEXTURE_2D, m_ID));

			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

			//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Image.GetWidth(), m_Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetImageBuffer().data());
			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Image.GetWidth(), m_Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetImageBuffer().data()));

			GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		}

		void Texture::Load(const std::string& filename)
		{
			if (m_Image.Load(filename))
			{
				Bind();
				GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Image.GetWidth(), m_Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetImageBuffer().data()));
				Unbind();
			}
		}

		void Texture::NewBlankTexture(int width, int height)
		{
			Unbind();

			m_Image.CreateImage(width, height);

			Bind();
			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Image.GetWidth(), m_Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetImageBuffer().data()));
			Unbind();
		}
		void Texture::ResendTex()
		{
			Bind();
			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Image.GetWidth(), m_Image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_Image.GetImageBuffer().data()));
			Unbind();
		}
		//void Texture::save(const std::string& filename) {}
	} // namespace OpenGL
} // namespace Kewl