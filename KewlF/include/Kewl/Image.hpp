#pragma once

#include "String.hpp"

namespace Kewl
{

    class Image
    {
    private:


    public:
        Image() = default;
        Image(String& filename);
        virtual ~Image();
    };

} // namespace Kewl
