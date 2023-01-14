///////////////////////////////////////////////////////////////////////////////
//
// Color.h
//
// Description:
// A simple RGBA Color Class
//
// Usage:
//     #include <KewlF/Color.hpp>
//     ...
//     Color color;            // defaults to black
//     NormalizedColor nColor; // defaults to black
// or
//     Color color(255,0,0,255);        // for bright Red
//     NormalizedColor nColor(1,0,0,1); // for bright Red
// 
///////////////////////////////////////////////////////////////////////////////
#pragma once

using ColorComponent = uint8_t;
using NormalizedColorComponent = float_t;

struct Color{
    ColorComponent r = 0;
    ColorComponent g = 0;
    ColorComponent b = 0;
    ColorComponent a = 255;

    Color() {  }
    Color(ColorComponent _r, ColorComponent _g, ColorComponent _b, ColorComponent _a) : r(_r), g(_r), b(_b), a(_a) {}
    Color(const Color &c) : r(c.r), g(c.r), b(c.b), a(c.a) {}
};

struct NormalizedColor {
    NormalizedColorComponent r = 0.0f;
    NormalizedColorComponent g = 0.0f;
    NormalizedColorComponent b = 0.0f;
    NormalizedColorComponent a = 1.0f;

    NormalizedColor() {  }
    NormalizedColor(NormalizedColorComponent _r, NormalizedColorComponent _g, NormalizedColorComponent _b, NormalizedColorComponent _a) : r(_r), g(_r), b(_b), a(_a) {}
    NormalizedColor(const Color& c) : r(c.r), g(c.r), b(c.b), a(c.a) {}
};
