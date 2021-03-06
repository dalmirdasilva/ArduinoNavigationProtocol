#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_ACK_MESSAGE
#define NAVIGATION_PROTOCOL_ACK_MESSAGE

#define NAVIGATION_PROTOCOL_ACK_MESSAGE_FLAGS           0x00

class AckMessage: public Message {

    struct Payload {

        uint8_t at;
        uint8_t ackedId;

    public:

        Payload() :
                ackedId(0), at(0) {
        }

        uint8_t getAt() const {
            return at;
        }

        void setAt(uint8_t at) {
            this->at = at;
        }

        uint8_t getAckedId() const {
            return ackedId;
        }

        void setAckedId(uint8_t ackedId) {
            this->ackedId = ackedId;
        }
    } _payload;

public:

    AckMessage(uint8_t ackedId);

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_ACK_MESSAGE
