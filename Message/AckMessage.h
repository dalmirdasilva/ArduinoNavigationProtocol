#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_ACK_MESSAGE
#define NAVIGATION_PROTOCOL_ACK_MESSAGE

#define NAVIGATION_PROTOCOL_ACK_MESSAGE_FLAGS           0x00

class AckMessage: public Message {

    struct Payload {

        uint8_t at;

    public:

        Payload() :
                at(0) {
        }

        uint8_t getAt() const {
            return at;
        }

        void setAt(uint8_t at) {
            this->at = at;
        }
    } _payload;

public:

    AckMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_ACK_MESSAGE
