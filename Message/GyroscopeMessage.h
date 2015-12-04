#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
#define NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE

#define NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE_FLAGS           0x00

class GyroscopeMessage: public Message {

    struct Payload {

        uint8_t x;

        Payload() :
                x(0) {
        }

    } _payload;

public:

    GyroscopeMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
