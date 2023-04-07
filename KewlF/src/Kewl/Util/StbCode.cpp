#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include <stb/stb_image_resize.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#pragma warning( push )
#pragma warning(disable:4996)
#include <stb/stb_image_write.h>
#pragma warning( pop )
