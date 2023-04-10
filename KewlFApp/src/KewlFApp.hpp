// KewlF.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <Kewl\App.hpp>

class KewlFApp : public Kewl::App {
protected:
    // Don't worry about calling these they should be called 
    // automatically by our built-in main fuction in order.
    void init() override;    // called first  // implement this to setup data, windows, etc...
    int  runApp() override;  // called second // it is recommended that you at least implement this as your primary entry point
    void cleanUp() override; // called third  // use this to clean up anything that may need to from the init call

public:
    KewlFApp();
    ~KewlFApp();

    int processCmdLine(int argCnt, char** argList) override;
    void isMyKewlFAppAccessable();
};

extern KewlFApp kewlApp;
