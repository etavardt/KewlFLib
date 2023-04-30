// KewlF.cpp : Defines the entry point for the application.
//

#include "KewlFApp.hpp"
#include <cassert>
#include <Kewl/Exception.hpp>
#include <Kewl/Logger.hpp>
#include <Kewl/Color.hpp>
#include "KewlFClass.hpp"

//using namespace Kewl;
//using Kewl::ERROR;
//using Kewl::INFO;
//using Kewl::ASIS;

KewlFApp kewlApp;

KewlFApp::KewlFApp() {
    LOG(INFO) << "KewlFApp Constructor" << std::endl;
}
KewlFApp::~KewlFApp() {
    LOG(INFO) << "KewlFApp Destructor" << std::endl;
}

int KewlFApp::processCmdLine(int argCnt, char** argList) {
    return 0;
}

void KewlFApp::init() {
    KewlFClass kewlClass;

    kewlClass.isMyKewlFAppAccessable();
}

int KewlFApp::runApp() {
    Kewl::Color color;
    Kewl::NormalizedColor nColor;

    assert(color.a == 255);
    assert(nColor.a == 1.0f);

    LOG(INFO) << "Hello World." << std::endl;
    LOG(ASIS) << "Hello World! Logged as is." << std::endl;
    std::cout << "Hello World! From std::cout!" << std::endl;
    throw Kewl::Exception("This exception was intentional!");
    return 0;
}

void KewlFApp::cleanUp() {

}

void KewlFApp::isMyKewlFAppAccessable() {
    LOG(INFO) << "Yes! I am visable when required." << std::endl;
}
