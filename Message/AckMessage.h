#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_ACK_MESSAGE
#define NAVIGATION_PROTOCOL_ACK_MESSAGE

#define NAVIGATION_PROTOCOL_ACK_MESSAGE_FLAGS           0x00

class AckMessage : public Message {

    struct AckMessagePayload {
    } _payload;

public:

    AckMessage();
};

#endif // NAVIGATION_PROTOCOL_ACK_MESSAGE
