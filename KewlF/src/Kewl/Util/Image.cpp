#include "Kewl/Util/Image.hpp"

#include <Kewl/Logger.hpp>
#include <Kewl/Exception.hpp>

#include <stb/stb_image.h>

namespace Kewl {

    Image::Image() {}
    Image::~Image() {
    }

    bool Image::CreateImage( uint32_t width, uint32_t height ) {
        bool successful = false;
        m_Filename.clear();
        m_Width = width;
        m_Height = height;
        m_Size = width * height * m_Comp;

        m_ImageBuffer.clear();
        m_ImageBuffer.resize( m_Size );

        successful = m_ImageBuffer.size() == m_Size;
        if (!successful) {
            LOG( ERROR ) << "Unable to create an image buffer!" << std::endl;
        }

        return successful;
    }

    bool Image::Load( const String& filename ) {
        bool successful = false;
        m_Filename = filename;
        stbi_set_flip_vertically_on_load( 1 );

        {
            int w, h, c;
            unsigned char* stbImage = stbi_load( filename.c_str(), &w, &h, &c, m_Comp );
            if (stbImage == nullptr) throw Exception("Unable to load image(" + filename + ")");
            m_Width = w;
            m_Height = h;
            m_CompFile = c;
            m_Size = m_Width * m_Height * m_Comp;
            m_ImageBuffer.clear();
            m_ImageBuffer.resize( m_Size );
            memcpy(m_ImageBuffer.data(), stbImage, m_Size );

            stbi_image_free( stbImage );
        }

        successful = m_ImageBuffer.size() == m_Size;
        if (!successful) {
            LOG( ERROR ) << "Unable to load file(\"" << filename << "\") for reason: " << stbi_failure_reason() << std::endl;
        }

        return successful;
    }
    //TODO: Implement Write/Save
    void Image::Save( const String& filename ) {}
    void Image::Save() {}

}// namespace Kewl