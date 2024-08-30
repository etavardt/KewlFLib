#include "Kewl/Util/Color.hpp"
namespace Kewl {
    // Color
    Color::Color() {}
    Color::Color(ColorComponentType _r, ColorComponentType _g, ColorComponentType _b, ColorComponentType _a) : r(_r), g(_g), b(_b), a(_a) {}
    Color::Color(const glm::vec4& _c) : r(_c.r), g(_c.g), b(_c.b), a(_c.a) {}
    Color& Color::operator=(glm::vec4& _c)
    {
        r = _c.r; g = _c.g; b = _c.b; a = _c.a; return *this;
    }

    void Color::normalize()
    {
        //std::valarray vals{ r,g,b,a };
        //ColorComponentType max = vals.max();
        ColorComponentType max = std::max(r, std::max(g, std::max(b, a)));
        r /= max;
        g /= max;
        b /= max;
        a /= max;
    }

    RGBAData Color::GetRGBAData()
    {
        if (r > 1.0f || g > 1.0f || b > 1.0f || a > 1.0f)
        {
            normalize();
        }
        RGBADataComponentType _r = (RGBADataComponentType)(r * 255.0f);
        RGBADataComponentType _g = (RGBADataComponentType)(g * 255.0f);
        RGBADataComponentType _b = (RGBADataComponentType)(b * 255.0f);
        RGBADataComponentType _a = (RGBADataComponentType)(a * 255.0f);

        //uint32_t result = (_a << 24) | (_b << 16) | (_g << 8) | _r;
        return (_a << 24) | (_b << 16) | (_g << 8) | _r;
    }

    // ColorRGBA
    Color ColorRGBA::GetColor()
    {
        return Color{ r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f };
    }
    RGBAData ColorRGBA::GetRGBAData()
    {
        return (a << 24) | (b << 16) | (g << 8) | r;
        //RGBAData retVal{};
        //retVal += a; retVal <<= 8;
        //retVal += b; retVal <<= 8;
        //retVal += g; retVal <<= 8;
        //retVal += r;
        //return retVal;
    }

} // namespace Kewl