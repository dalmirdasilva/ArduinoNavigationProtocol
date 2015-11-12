#include <Message.h>

#ifndef NAVIGATION_PROTOCOL_GPS_MESSAGE
#define NAVIGATION_PROTOCOL_GPS_MESSAGE

#define NAVIGATION_PROTOCOL_GPS_MESSAGE_FLAGS           0x00

class GpsMessage : public Message {

    struct Payload {
        unsigned char x;
    } _payload;

public:

    GpsMessage();
};

#endif // NAVIGATION_PROTOCOL_GPS_MESSAGE
