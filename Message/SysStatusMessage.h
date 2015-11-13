#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE
#define NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE

#define NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE_FLAGS           0x00

class SysStatusMessage: public Message {

    struct Payload {

        uint8_t batteryVoltage;
        uint8_t batteryRemaining;

    public:

        Payload() :
                batteryVoltage(0), batteryRemaining(0) {
        }

        uint8_t getBatteryRemaining() const {
            return batteryRemaining;
        }

        void setBatteryRemaining(uint8_t batteryRemaining) {
            this->batteryRemaining = batteryRemaining;
        }

        uint8_t getBatteryVoltage() const {
            return batteryVoltage;
        }

        void setBatteryVoltage(uint8_t batteryVoltage) {
            this->batteryVoltage = batteryVoltage;
        }

    } _payload;

public:

    SysStatusMessage();

    Payload *getPayload();
};

#endif // NAVIGATION_PROTOCOL_SYS_STATUS_MESSAGE
