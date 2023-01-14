// KewlF.cpp : Defines the entry point for the application.
//

#include "KewlFApp.hpp"
#include <cassert>
#include <KewlF/Exception.hpp>
#include <KewlF/Logger.hpp>
#include <KewlF/Color.hpp>
#include "KewlFClass.hpp"

KewlFApp kewlApp;

KewlFApp::KewlFApp() {
    LOG(INFO) << "KewlFApp Constructed" << std::endl;
}
KewlFApp::~KewlFApp() {
    LOG(INFO) << "KewlFApp Destructed" << std::endl;
}

int KewlFApp::processCmdLine(int argCnt, char** argList) {
    return 0;
}

void KewlFApp::init() {
    KewlFClass kewlClass;

    kewlClass.isMyKewlFAppAccessable();
}

int KewlFApp::runApp() {
    Color color;
    NormalizedColor nColor;

    assert(color.a == 255);
    assert(nColor.a == 1.0f);

    LOG(INFO) << "Hello World." << std::endl;
    throw Exception("This exception was intentional!");
    return 0;
}

void KewlFApp::cleanUp() {

}

void KewlFApp::isMyKewlFAppAccessable() {
    LOG(INFO) "Yes! I am visable when required." << std::endl;
}
