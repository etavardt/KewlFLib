//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
#include <iostream>

#include "Kewl/App.hpp"
#include "Kewl/Exception.hpp"
#include "Kewl/Logger.hpp"

using std::cout;
using std::cerr;
using std::endl;

using Kewl::App;
using Kewl::Exception;
//using Kewl::ERROR;

//extern "C"
int main(int ac, char **av) {
    App &app = App::getApp();  // We expect the App has been created globally via a UserApp instance.
    try {
        app.processCmdLine(ac, av);
        app.init();
        app.runApp();
    } catch (Exception &e) {
        LOG(ERROR) << "Unhandled Exception caught in main: " << e.getMsg() << endl;
    } catch (const std::exception &e) {
        LOG(ERROR) << "Unhandled std::exception caught in main: " << e.what() << endl;
    } catch (...) {
        LOG(ERROR) << "Unhandled Unknown Exception caught in main" << endl;
    }

    app.cleanUp();
    return 0;
} /* end of main() */
