// KewlF.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include "App.hpp"

class KewlFApp : public App {
protected:
	static KewlFApp &kewlApp;

    KewlFApp();
    ~KewlFApp();

    void init() override;
    void cleanUp() override; // Clean up what init(ed) items
    int runApp() override;

public:
    static inline KewlFApp& getApp() { return kewlApp; }
    static KewlFApp& getInstance();

    int processCmdLine(int argCnt, char** argList) override;
};
// TODO: Reference additional headers your program requires here.
