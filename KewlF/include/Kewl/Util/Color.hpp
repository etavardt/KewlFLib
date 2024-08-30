#pragma once

#include <valarray>

#include <glm/glm.hpp>

namespace Kewl
{
    using ColorRGBAComponentType = unsigned char;
    using RGBAData = uint32_t;

    using ColorComponentType = float;
    using RGBADataComponentType = uint8_t;

    struct Color
    {
        ColorComponentType r {};
        ColorComponentType g {};
        ColorComponentType b {};
        ColorComponentType a {};

        Color();
        Color(ColorComponentType _r, ColorComponentType _g, ColorComponentType _b, ColorComponentType _a);
        Color(const glm::vec4& _c);
        Color& operator=(glm::vec4& _c);

        void normalize();
        RGBAData GetRGBAData();

        //static RGBAData ConvertRGBAData(glm::vec4 _color);
    };

    struct ColorRGBA
    {
        ColorRGBAComponentType r {};
        ColorRGBAComponentType g {};
        ColorRGBAComponentType b {};
        ColorRGBAComponentType a {};

        Color GetColor();
        RGBAData GetRGBAData();
    };

} // namespace Kewl