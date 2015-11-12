#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_GPS_MESSAGE
#define NAVIGATION_PROTOCOL_GPS_MESSAGE

#define NAVIGATION_PROTOCOL_GPS_MESSAGE_FLAGS           0x00

class GpsMessage: public Message {

    struct Payload {
        int32_t latitude;
        int32_t longitude;
        int32_t altitude;
    } _payload;

public:

    GpsMessage();
};

#endif // NAVIGATION_PROTOCOL_GPS_MESSAGE
