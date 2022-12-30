#include "App.hpp"

#include "Window.hpp"
#include "Exception.hpp"
#include "Logger.hpp"

App *App::app = nullptr;

App::App() {
//    registerEventHandling();
}

App::~App() {
 //   unRegisterEventHandling();
}

void App::init() {

}

void App::cleanUp() {
//    LOG(INFO) << "Clean up.";
}

App &App::getApp() {
    if (app == nullptr) throw "No Application Object Exists";
    return *app;
}

int App::runApp() {
    processEventLoop();
    return 1;
}

void App::processEventLoop() {
//    while (EventHandler::pollAndHandleEvent()) {
        // TODO: Timing and Graphics processing.
        //LOG(TRACE) << "In App::processEventLoop()";
//    };
}
