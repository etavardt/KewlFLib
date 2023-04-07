#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <Kewl/App.hpp>
#include <Kewl/Logger.hpp>
namespace Kewl
{
    namespace GLFW
    {
        class KewlGlfwApp : public App
        {
        protected:
            inline void HandleGlfwError() {
                glfwSetErrorCallback([] (int error, const char* description)
                {
                    LOG(ASIS) << "GLFW Error(" << error << "): " << description << std::endl;
                });
            }

        public:
            KewlGlfwApp();
            ~KewlGlfwApp();

        };
    } // namespace GLFW
} // namespace Kewl