#pragma once

#include <iostream>
//#include "App.hpp"

class App;

class KewlFApp : public App {
protected:
	//static KewlFApp &kewlApp;

    KewlFApp();
    ~KewlFApp();

    void init() override;    // Not required but used to keep runApp clean
    void cleanUp() override; // Same as init's comment but use to Clean up anything init(ed)
    int runApp() override;   // Use this for your primary program implementation

public:
    static KewlFApp& getApp() { return kewlApp; }
    static KewlFApp& getInstance();

    int processCmdLine(int argCnt, char** argList) override;
};
