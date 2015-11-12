#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
#define NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE

#define NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE_FLAGS           0x00

class GyroscopeMessage: public Message {

    struct Payload {
        unsigned char x;
    } _payload;

public:

    GyroscopeMessage();
};

#endif // NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
