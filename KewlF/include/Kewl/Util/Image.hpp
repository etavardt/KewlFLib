#pragma once

#include <memory>
#include <vector>

#include <Kewl/String.hpp>
//#include <stb/stb_image.h>

//#include "Kewl/Util/Counter.hpp"
//enum class ImageFileType : unsigned char {
//	BMP = 0,
//	HDR,
//	JPG,
//	PNG,
//	TGA
//};

namespace Kewl
{
    using ImageBufferType = unsigned char;
    //*    using ImageBuffer = ImageBufferType*;
    using ImageBuffer = std::vector<ImageBufferType>;

    class Image
    {
        //     N=#comp     components
        //       1           grey
        //       2           grey, alpha
        //       3           red, green, blue
        //       4           red, green, blue, alpha
        enum Comp
        {
            Unkown = 0,
            Grey = 1,
            GreyAlpha,
            RGB,
            RGBA
        };

    private:

    protected:
        uint32_t m_Width = 0;
        uint32_t m_Height = 0;
        uint32_t m_Size = 0;

        const uint32_t m_Comp = Comp::RGBA; // assume RGBA 8bits per channel, 32 bits per pixel, 4 bytes per pixel
        uint32_t m_CompFile = 0;

        String m_Filename;

        ImageBuffer m_ImageBuffer;

    public:
        Image();
        ~Image();

        bool CreateImage(uint32_t width, uint32_t height);
        virtual bool Load(const String& filename);
        virtual void Save(const String& filename);
        virtual void Save();

        inline ImageBuffer &GetImageBuffer() { return m_ImageBuffer; }
        inline ImageBufferType* GetImageBufferData() { return m_ImageBuffer.data(); }

        inline const uint32_t GetWidth() const { return m_Width; }
        inline const uint32_t GetHeight() const { return m_Height; }
        inline const uint32_t GetSize() const { return m_Size; }
        inline const String& GetFilename() const { return m_Filename; }
        inline const uint32_t GetChannelCount() const { return m_Comp; }

        //inline Counter GetWidthCounter() { return Counter(m_Width - 1); }
        //inline Counter GetHeightCounter() { return Counter(m_Height - 1); }
    };
}// namespace Kewl