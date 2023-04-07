#include "KewlGlfwApp.hpp"

#define GLAD_GL_IMPLEMENTATION
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <Kewl/Logger.hpp>
#include <Kewl/Exception.hpp>

namespace Kewl
{
    namespace GLFW
    {
        KewlGlfwApp::KewlGlfwApp() {
            /* Initialize GLFW */
            if (!glfwInit())
                throw Exception("Failed call to glfwInit");

#if defined KEWLF_DEBUG
            HandleGlfwError();
#endif
        }

        KewlGlfwApp::~KewlGlfwApp() {
            glfwTerminate();
        }
    } // namespace GLFW
} // namespace Kewl