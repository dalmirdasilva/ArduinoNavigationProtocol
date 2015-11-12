#include <Message.h>

#ifndef SIMPLE_NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
#define SIMPLE_NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE

#define SNP_GYROSCOPE_MESSAGE_FLAGS           0x00

class GyroscopeMessage : public Message {

    struct Payload {
        unsigned char x;
    } _payload;

public:

    GyroscopeMessage();
};

#endif // SIMPLE_NAVIGATION_PROTOCOL_GYROSCOPE_MESSAGE
