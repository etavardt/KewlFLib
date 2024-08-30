#include "Kewl/Window.hpp"

#include "Kewl/App.hpp"
#include "Kewl/String.hpp"
#include "Kewl/Exception.hpp"
#include "Kewl/Logger.hpp"

namespace Kewl
{

    Window::Window() {
        LOG(TRACE) << "Window::Window()." << std::endl;
    }

    Window::~Window() {
        LOG(TRACE) << "Window::~Window()." << std::endl;

        //unRegisterEventHandling();

    }

    void Window::createWindow(bool showWindow /* = false */) {

        LOG(TRACE) << "Pre Window.init()." << std::endl;

        // width  = desktopDm.w;
        // height = desktopDm.h;
    }

    void Window::init() {
        //    aspectRatio = (1.0f * desktopDm.w)/desktopDm.h;
        //    minWidth  = desktopDm.w/2;
        //    minHeight = desktopDm.h/2;
    }

    bool Window::toggleFullScreen() {
        LOG(TRACE) << "In Window::toggleFullScreen." << std::endl;

        return 0;
    }

    void Window::displayText(const String& str, const int x, const int y) {

    };

    void Window::displayImage(Image& image, const int x, const int y) {

    }

    // Event functions

} // namespace Kewl
