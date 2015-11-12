#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE
#define NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE

#define NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE_FLAGS           0x00

class SysStatusMessage: public Message {

    struct Payload {
        uint8_t batteryVoltage;
        uint8_t batteryRemaining;
    } _payload;

public:

    SysStatusMessage();
};

#endif // NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE
