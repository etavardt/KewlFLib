///////////////////////////////////////////////////////////////////////////////
//
// App.h
//
// Description:
// A custom foundation base Application Class to aid in starting and developing
// a C++ application.  It is meant to be extended and not used directly. The
// main function is meant to be hidden in the foundation library.
//
// Usage:
// 
// Step 1: Create your App Class and extend App as public
//   i.e.:
//      #include "App.hpp"
// 
//      class YourKewlApp : public App {
//      private:
//          ...
//      public:
//          ...
//      }
// or
//      #include "App.hpp"
// 
//      class YourKewlApp : public App {
//      private:
//          static YourKewlApp yourKewlApp;
//          ...
//      public:
//          ...
//          // Implement a getter for access to your app from other code units if needed.
//          inline YourKewlApp& getYourKewlApp() const { return yourKewlApp; }
//      }

// Step 2: Create your app object globally in your yourKewlApp.cpp file
//      i.e.:
//          YourKewlApp yourKewlApp;
//      or
//          YourKewlApp YourKewlApp::yourKewlApp;
// 
///////////////////////////////////////////////////////////////////////////////
#pragma once

int main(int ac, char** av);

namespace Kewl
{
    //#include "EventHandler.hpp"

    class App
    { //: public EventHandler {
    public:
        void operator=(App const&) = delete;

        virtual int processCmdLine(int _argCnt, char** _argList) {
            argCnt = _argCnt;
            argList = _argList;
            return 1;
        }
        char* getAppFileName() {
            return argList[0];
        }

        friend int ::main(int ac, char** av);

    protected:
        static App& getApp();

        App(); // Default constructor hidden to make it a singleton
        App(App const&) = delete;
        ~App();

        virtual void init();    // Not required but used to keep runApp clean
        virtual void cleanUp(); // Same as init's comment but use to Clean up anything init(ed)
        virtual int runApp();   // Use this for your primary program implementation

    private:
        static App* app;

        int argCnt = 0;
        char** argList = nullptr;

        virtual void processEventLoop();

        //    virtual void onShown(WindowEvent &event) override;
    };
} // namespace Kewl