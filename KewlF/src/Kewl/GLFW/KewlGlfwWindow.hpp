#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Kewl/Window.hpp>
#include "Kewl/GLFW/Input/InputInterface.hpp"

namespace Kewl
{
    namespace GLFW
    {

        class KewlGlfwWindow : public Window, public Kewl::InputInterface
        {
        private:
            virtual void SetGlfwHints() {};

            uint32_t m_OrgWidth = 0;
            uint32_t m_OrgHeight = 0;

        protected:
            GLFWwindow* m_GlfwWindow = nullptr;

            // Window properties used in creation
            GLFWmonitor* m_Monitor = nullptr;
            GLFWwindow* m_Share = nullptr;

            KewlGlfwWindow();
            ~KewlGlfwWindow();
            KewlGlfwWindow(const KewlGlfwWindow&) = delete;
            KewlGlfwWindow& operator=(const KewlGlfwWindow&) = delete;
            KewlGlfwWindow(const KewlGlfwWindow&&) = delete;
            KewlGlfwWindow& operator=(const KewlGlfwWindow&&) = delete;

            void GlfwCreateWindow(int32_t width, int32_t height, String title);

            inline void GlfwShow() {
                ::glfwShowWindow(m_GlfwWindow);
            }
            inline void GlfwHide() {
                ::glfwHideWindow(m_GlfwWindow);
            }
            inline bool GlfwShouldClose() {
                return ::glfwWindowShouldClose(m_GlfwWindow);
            }
            inline void GlfwPollEvents() {
                ::glfwPollEvents();
            }
            inline void GlfwSwapBuffers() {
                ::glfwSwapBuffers(m_GlfwWindow);
            }
            inline void GlfwDefaultWindowHints() {
                ::glfwDefaultWindowHints();
            }
            inline void GlfwWindowHint(int hint, int value) {
                ::glfwWindowHint(hint, value);
            }

            // Events
            inline void HandleOnResize() {
                glfwSetFramebufferSizeCallback(m_GlfwWindow, [] (GLFWwindow* window, int width, int height)
                {
                    static_cast<KewlGlfwWindow*>(glfwGetWindowUserPointer(window))->OnResize(static_cast<uint32_t>(width), static_cast<uint32_t>(height));
                });
            }
            virtual void OnResize(uint32_t width, uint32_t height);

            inline void HandleOnKeyPress() {
                glfwSetKeyCallback(m_GlfwWindow, [] (GLFWwindow* window, int key, int scancode, int action, int mods)
                {
                    static_cast<KewlGlfwWindow*>(glfwGetWindowUserPointer(window))->OnKeyPress(key, scancode, action, mods);
                });
            }
            inline virtual void OnKeyPress(int key, int scancode, int action, int mods) {}

        public:
            GLFWwindow* GetGlfwWindow() override {
                return m_GlfwWindow;
            }
        };
        // void glfwDefaultWindowHints(void);
        // Resets all window hints to their default values.More...

        // void glfwWindowHint(int hint, int value);
        // Sets the specified window hint to the desired value.More...

        // void glfwWindowHintString(int hint, const char* value);
        // Sets the specified window hint to the desired value.More...

        // GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
        // Creates a windowand its associated context.More...

        // void glfwDestroyWindow(GLFWwindow* window);
        // Destroys the specified windowand its context.More...

        // int  glfwWindowShouldClose(GLFWwindow* window);
        // Checks the close flag of the specified window.More...

        // void glfwSetWindowShouldClose(GLFWwindow* window, int value);
        // Sets the close flag of the specified window.More...

        // void glfwSetWindowTitle(GLFWwindow* window, const char* title);
        // Sets the title of the specified window.More...

        // void glfwSetWindowIcon(GLFWwindow* window, int count, const GLFWimage* images);
        // Sets the icon for the specified window.More...

        // void glfwGetWindowPos(GLFWwindow* window, int* xpos, int* ypos);
        // Retrieves the position of the content area of the specified window.More...

        // void glfwSetWindowPos(GLFWwindow* window, int xpos, int ypos);
        // Sets the position of the content area of the specified window.More...

        // void glfwGetWindowSize(GLFWwindow* window, int* width, int* height);
        // Retrieves the size of the content area of the specified window.More...

        // void glfwSetWindowSizeLimits(GLFWwindow* window, int minwidth, int minheight, int maxwidth, int maxheight);
        // Sets the size limits of the specified window.More...

        // void glfwSetWindowAspectRatio(GLFWwindow* window, int numer, int denom);
        // Sets the aspect ratio of the specified window.More...

        // void glfwSetWindowSize(GLFWwindow* window, int width, int height);
        // Sets the size of the content area of the specified window.More...

        // void glfwGetFramebufferSize(GLFWwindow* window, int* width, int* height);
        // Retrieves the size of the framebuffer of the specified window.More...

        // void glfwGetWindowFrameSize(GLFWwindow* window, int* left, int* top, int* right, int* bottom);
        // Retrieves the size of the frame of the window.More...

        // void glfwGetWindowContentScale(GLFWwindow* window, float* xscale, float* yscale);
        // Retrieves the content scale for the specified window.More...

        // float glfwGetWindowOpacity(GLFWwindow* window);
        // Returns the opacity of the whole window.More...

        // void glfwSetWindowOpacity(GLFWwindow* window, float opacity);
        // Sets the opacity of the whole window.More...

        // void glfwIconifyWindow(GLFWwindow* window);
        // Iconifies the specified window.More...

        // void glfwRestoreWindow(GLFWwindow* window);
        // Restores the specified window.More...

        // void glfwMaximizeWindow(GLFWwindow* window);
        // Maximizes the specified window.More...

        // void glfwShowWindow(GLFWwindow* window);
        // Makes the specified window visible.More...

        // void glfwHideWindow(GLFWwindow* window);
        // Hides the specified window.More...

        // void glfwFocusWindow(GLFWwindow* window);
        // Brings the specified window to frontand Sets input focus.More...

        // void glfwRequestWindowAttention(GLFWwindow* window);
        // Requests user attention to the specified window.More...

        // GLFWmonitor* glfwGetWindowMonitor(GLFWwindow* window);
        // Returns the monitor that the window uses for full screen mode.More...

        // void glfwSetWindowMonitor(GLFWwindow* window, GLFWmonitor* monitor, int xpos, int ypos, int width, int height, int refreshRate);
        // Sets the mode, monitor, video modeand placement of a window.More...

        // int  glfwGetWindowAttrib(GLFWwindow* window, int attrib);
        // Returns an attribute of the specified window.More...

        // void glfwSetWindowAttrib(GLFWwindow* window, int attrib, int value);
        // Sets an attribute of the specified window.More...

        // void glfwSetWindowUserPointer(GLFWwindow* window, void* pointer);
        // Sets the user pointer of the specified window.More...

        // void* glfwGetWindowUserPointer(GLFWwindow* window);
        // Returns the user pointer of the specified window.More...

        // GLFWwindowposfun glfwSetWindowPosCallback(GLFWwindow* window, GLFWwindowposfun callback);
        // Sets the position callback for the specified window.More...

        // GLFWwindowsizefun glfwSetWindowSizeCallback(GLFWwindow* window, GLFWwindowsizefun callback);
        // Sets the size callback for the specified window.More...

        // GLFWwindowclosefun glfwSetWindowCloseCallback(GLFWwindow* window, GLFWwindowclosefun callback);
        // Sets the close callback for the specified window.More...

        // GLFWwindowrefreshfun glfwSetWindowRefreshCallback(GLFWwindow* window, GLFWwindowrefreshfun callback);
        // Sets the refresh callback for the specified window.More...

        // GLFWwindowfocusfun glfwSetWindowFocusCallback(GLFWwindow* window, GLFWwindowfocusfun callback);
        // Sets the focus callback for the specified window.More...

        // GLFWwindowiconifyfun glfwSetWindowIconifyCallback(GLFWwindow* window, GLFWwindowiconifyfun callback);
        // Sets the iconify callback for the specified window.More...

        // GLFWwindowmaximizefun glfwSetWindowMaximizeCallback(GLFWwindow* window, GLFWwindowmaximizefun callback);
        // Sets the maximize callback for the specified window.More...

        // GLFWframebuffersizefun glfwSetFramebufferSizeCallback(GLFWwindow* window, GLFWframebuffersizefun callback);
        // Sets the framebuffer resize callback for the specified window.More...

        // GLFWwindowcontentscalefun glfwSetWindowContentScaleCallback(GLFWwindow* window, GLFWwindowcontentscalefun callback);
        // Sets the window content scale callback for the specified window.More...

        // void glfwPollEvents(void);
        // Processes all pending events.More...

        // void glfwWaitEvents(void);
        // Waits until events are queuedand processes them.More...

        // void glfwWaitEventsTimeout(double timeout);
        // Waits with timeout until events are queuedand processes them.More...

        // void glfwPostEmptyEvent(void);
        // Posts an empty event to the event queue.More...

        // void glfwSwapBuffers(GLFWwindow* window);
        // Swaps the frontand back buffers of the specified window.More...
    } // namespace GLFW
} // namespace Kewl
