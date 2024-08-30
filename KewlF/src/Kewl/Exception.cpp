#include "Kewl/Exception.hpp"

#include <iostream>

#include "Kewl/String.hpp"
#include "Kewl/StackTrace.hpp"

namespace Kewl
{

    SharedStringPointer Exception::getStackTrace() {
        SharedStringPointer sTracePtr = makeSharedStringPointer();
        String stMsg = st.getStackTrace();

        sTracePtr->append(stMsg);

        return sTracePtr;
    }

    const String Exception::getMsg() {
        String msg;

        msg.append("Exception Thrown: ");
        msg.append(what());
        msg.append(*getStackTrace());

        return msg;
    }

} // namespace Kewl
