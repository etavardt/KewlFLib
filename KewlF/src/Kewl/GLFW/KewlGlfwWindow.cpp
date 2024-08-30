#include "Kewl/GLFW/KewlGlfwWindow.hpp"

#include <Kewl/Exception.hpp>

#include "Kewl/OpenGL/OpenGLDebug.hpp"

namespace Kewl
{
    namespace GLFW
    {

        KewlGlfwWindow::KewlGlfwWindow() {
        }

        KewlGlfwWindow::~KewlGlfwWindow() {
            if (m_GlfwWindow != nullptr)
            {
                glfwDestroyWindow(m_GlfwWindow);
            }
        }

        void KewlGlfwWindow::GlfwCreateWindow(int32_t width, int32_t height, String title) {
            m_OrgWidth = width;
            m_OrgHeight = height;
            SetGlfwHints();

            m_GlfwWindow = ::glfwCreateWindow(width, height, title.c_str(), m_Monitor, m_Share);
            if (!m_GlfwWindow)
            {
                throw Exception("Failed during call to glfwCreateWindow");
            }
            glfwMakeContextCurrent(m_GlfwWindow);
            // allows our event handlers to work without error
            glfwSetWindowUserPointer(m_GlfwWindow, this);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            {
                std::cerr << "Failed to initialize GLAD" << std::endl;
                throw "Failed call to gladLoadGLLoader!";
            }

            std::cout << "- Shading Language = " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
            std::cout << "- Version = " << glGetString(GL_VERSION) << std::endl;
            std::cout << "- Vendor = " << glGetString(GL_VENDOR) << std::endl;
            std::cout << "- Renderer = " << glGetString(GL_RENDERER) << std::endl << std::endl;

            GLint numExtensions;
            glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
            std::cout << "- Extensions" << std::endl;
            for (GLint i = 0; i < numExtensions; i++)
            {
                std::cout << glGetStringi(GL_EXTENSIONS, i) << std::endl;
            }

            Kewl::OpenGL::glDebug::initialize();
        }

        void KewlGlfwWindow::OnResize(uint32_t width, uint32_t height) {
            glfwSetWindowSize(m_GlfwWindow, width, height);
            glfwSetWindowAspectRatio(m_GlfwWindow, m_OrgWidth, m_OrgHeight);
            glViewport(0, 0, width, height);
        }
    } // namespace GLFW
} // namespace Kewl