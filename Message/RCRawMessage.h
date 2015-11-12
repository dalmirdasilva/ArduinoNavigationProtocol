#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_RC_RAW_MESSAGE
#define NAVIGATION_PROTOCOL_RC_RAW_MESSAGE

#define NAVIGATION_PROTOCOL_RC_RAW_MESSAGE_FLAGS           NAVIGATION_PROTOCOL_MESSAGE_FLAG_NEED_ACK

class RCRawMessage: public Message {

    struct Payload {
        uint16_t channel1;
        uint16_t channel2;
        uint16_t channel3;
        uint16_t channel4;
        uint16_t channel5;
        uint16_t channel6;
        uint16_t channel7;
        uint16_t channel8;
    } _payload;

public:

    RCRawMessage();
};

#endif // NAVIGATION_PROTOCOL_RC_RAW_MESSAGE
