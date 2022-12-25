// KewlF.cpp : Defines the entry point for the application.
//

#include "KewlFApp.h"
#include "Exception.hpp"

KewlFApp& KewlFApp::kewlApp = KewlFApp::getInstance();

KewlFApp::KewlFApp() {
    std::cout << "KewlFApp Constructed" << std::endl;
}
KewlFApp::~KewlFApp() {
    std::cout << "KewlFApp Destructed" << std::endl;
}

int KewlFApp::processCmdLine(int argCnt, char** argList) {
    return 0;
}

void KewlFApp::init() {

}

KewlFApp& KewlFApp::getInstance() {
    static KewlFApp instance; // should be created on heap? and there is only one and should be freed upon exit of the executable
    app = &instance; // this allows the underlying main function to hook into yourApp
    return instance;
}

int KewlFApp::runApp() {
    std::cout << "Hello CMake." << std::endl;
    throw Exception("Test this!");
    return 0;
}

void KewlFApp::cleanUp() {

}
