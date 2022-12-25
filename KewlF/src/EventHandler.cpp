//#include "easylogging++.h"
#include "EventHandler.hpp"

#include "Exception.hpp"
#include "Window.hpp"

#include "easylogging++.h"
#include "unused_macros.hpp"

#undef UNHANDLED
#define UNHANDLED(x) LOG(DEBUG) << "Unhandled Event(" << x.type << ")";
//#define UNHANDLED(x) (void)(x);

//typedef Exception EventException;
class EventException : public Exception {};

RegisteredEventHandlerMap EventHandler::registeredEventHandlers;

// int EventHandler::registerEventHandling(EventHandler &ehObject) {
//     registeredEventHandlers.insert(RegisteredEventHandlerPair(ehObject.id, ehObject));
//     return 1;
// }
int EventHandler::registerEventHandling() {
    registeredEventHandlers.insert(RegisteredEventHandlerPair(id, *this));
    return 1;
}

void EventHandler::unRegisterEventHandling() {
    registeredEventHandlers.erase(id);
}

bool EventHandler::pollAndHandleEvent() {
    return 0;
}

#undef UNHANDLED