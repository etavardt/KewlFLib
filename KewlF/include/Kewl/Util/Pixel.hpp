#pragma once
#include <vector>
#include "Kewl/Util/Color.hpp"
namespace Kewl {

    using Pixel = ColorRGBA;
    //using Pixels = std::vector<Pixel>;
    //using PixelRow = Pixels;
    //using PixelRows = std::vector<PixelRow>;

    class Pixels {
    public:
        uint32_t w;
        uint32_t h;
        unsigned char* data;

        ColorRGBA* GetDataArray() { return reinterpret_cast<ColorRGBA*>(data); }

        ColorRGBA& GetPixelColor( uint32_t x, uint32_t y ) {
            uint32_t colorSize = sizeof( ColorRGBA );
            uint32_t xPos = x * colorSize;
            uint32_t yPos = y * (w * colorSize);
            uint32_t pixelPos = xPos * yPos;

            return reinterpret_cast<ColorRGBA&>(data[pixelPos]);
        }
        void SetPixelColor( uint32_t x, uint32_t y, ColorRGBA c ) {
            uint32_t colorSize = sizeof( ColorRGBA );
            uint32_t xPos = x * colorSize;
            uint32_t yPos = y * (w * colorSize);
            uint32_t pixelPos = xPos * yPos;
            data[pixelPos++] = c.r;
            data[pixelPos++] = c.g;
            data[pixelPos++] = c.b;
            data[pixelPos++] = c.a;
        }
    };
} // namespace Kewl