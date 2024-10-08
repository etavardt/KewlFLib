#include "Kewl/App.hpp"

#include "Kewl/Window.hpp"
#include "Kewl/Exception.hpp"
#include "Kewl/Logger.hpp"

namespace Kewl
{

    App* App::app = nullptr;

    App::App() {
        LOG(TRACE) << "App Constructor" << std::endl;
        if (app != nullptr)
        {
            LOG(ERROR) << "The Application was already created" << std::endl;
            exit(-1);
        }
        app = this;
        //    registerEventHandling();
    }

    App::~App() {
        LOG(TRACE) << "App Deconstructor" << std::endl;
        //   unRegisterEventHandling();
        app = nullptr;
    }

    void App::init() {

    }

    void App::cleanUp() {
        //    LOG(INFO) << "Clean up.";
    }

    App& App::getApp() {
        if (app == nullptr) throw Exception("No Application Object Exists");
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

} // namespace Kewl
