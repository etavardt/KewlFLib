#include "Window.hpp"

#include "App.hpp"
#include "String.hpp"
#include "Exception.hpp"
#include "easylogging++.h"

Window::Window() {
}

Window::~Window() {
    LOG(TRACE) << "Window::~Window().";

    //unRegisterEventHandling();

}

void Window::createWindow() {

    LOG(TRACE) << "Pre Window.init().";
    init();

    // width  = desktopDm.w;
    // height = desktopDm.h;
}

void Window::show() {
}

void Window::init() {
//    aspectRatio = (1.0f * desktopDm.w)/desktopDm.h;
//    minWidth  = desktopDm.w/2;
//    minHeight = desktopDm.h/2;
}

bool Window::toggleFullScreen() {
    LOG(TRACE) << "In Window::toggleFullScreen.";

    return 0;
}

void Window::displayText(const String &str, const int x, const int y) {

};

void Window::displayImage(Image &image, const int x, const int y) {

}

// Event functions
