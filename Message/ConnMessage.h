#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_ACK_MESSAGE
#define NAVIGATION_PROTOCOL_ACK_MESSAGE

#define NAVIGATION_PROTOCOL_CONN_MESSAGE_FLAGS           NAVIGATION_PROTOCOL_MESSAGE_FLAG_NEED_ACK

class ConnMessage: public Message {

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

    ConnMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_ACK_MESSAGE
