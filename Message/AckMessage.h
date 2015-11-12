#include <Message.h>

#ifndef SIMPLE_NAVIGATION_PROTOCOL_ACK_MESSAGE
#define SIMPLE_NAVIGATION_PROTOCOL_ACK_MESSAGE

#define SNP_ACK_MESSAGE_FLAGS           0x00

class AckMessage : public Message {

    struct AckMessagePayload {
    } _payload;

public:

    AckMessage();
};

#endif // SIMPLE_NAVIGATION_PROTOCOL_ACK_MESSAGE
