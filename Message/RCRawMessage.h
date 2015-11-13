#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_RC_RAW_MESSAGE
#define NAVIGATION_PROTOCOL_RC_RAW_MESSAGE

#define NAVIGATION_PROTOCOL_RC_RAW_MESSAGE_FLAGS           NAVIGATION_PROTOCOL_MESSAGE_FLAG_NEED_ACK

class RCRawMessage: public Message {

public:

    struct Payload {

        uint16_t channel1;
        uint16_t channel2;
        uint16_t channel3;
        uint16_t channel4;
        uint16_t channel5;
        uint16_t channel6;
        uint16_t channel7;
        uint16_t channel8;

    public:

        Payload() :
                channel1(0), channel2(0), channel3(0), channel4(0), channel5(0), channel6(0), channel7(0), channel8(0) {
        }

        uint16_t getChannel1() const {
            return channel1;
        }

        void setChannel1(uint16_t channel1) {
            this->channel1 = channel1;
        }

        uint16_t getChannel2() const {
            return channel2;
        }

        void setChannel2(uint16_t channel2) {
            this->channel2 = channel2;
        }

        uint16_t getChannel3() const {
            return channel3;
        }

        void setChannel3(uint16_t channel3) {
            this->channel3 = channel3;
        }

        uint16_t getChannel4() const {
            return channel4;
        }

        void setChannel4(uint16_t channel4) {
            this->channel4 = channel4;
        }

        uint16_t getChannel5() const {
            return channel5;
        }

        void setChannel5(uint16_t channel5) {
            this->channel5 = channel5;
        }

        uint16_t getChannel6() const {
            return channel6;
        }

        void setChannel6(uint16_t channel6) {
            this->channel6 = channel6;
        }

        uint16_t getChannel7() const {
            return channel7;
        }

        void setChannel7(uint16_t channel7) {
            this->channel7 = channel7;
        }

        uint16_t getChannel8() const {
            return channel8;
        }

        void setChannel8(uint16_t channel8) {
            this->channel8 = channel8;
        }

    } _payload;

    RCRawMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_RC_RAW_MESSAGE
