#pragma once

#include <assert.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) glClearError();\
    x;\
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

namespace Kewl
{
    namespace OpenGL
    {
        void glClearError();
        bool glLogCall(const char* function, const char* file, int line);

        namespace glDebug {
	        void initialize();
	        bool isEnabled();
	        void glLogErrorMessage();
        } // namespace glDebug
	} // namespace OpenGL
} // namespace Kewl